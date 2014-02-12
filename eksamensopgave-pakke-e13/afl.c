/*
 * Programmør: Frederik Højholt Andersen   Underviser: Kurt Nørmark
 * Email: fhan13@student.aau.dk            Kursus: IMPR
 * Gruppe: B2-8                            Dato fuldført: ?? Nov, 2013
 * Studieretning: Software
 *
 * Eksamensopgave i Imperativ Programmering, 2013
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_LENJE_LENGDE 100
#define MAX_HOLD_NAVN 4
#define ANTAL_HOLD 12

typedef struct dato {
    int dag;
    enum maaned {
        january, februar, marts, april, maj, juni,
        july, august, september, oktober, november, december
    } maaned;
    int aar;
} dato;

typedef struct klokke {
    int timer;
    int minutter;
} klokke;

typedef struct kamp {
    int runde;
    dato dato;
    klokke tid;
    char hjemmehold[MAX_HOLD_NAVN];
    char udehold[MAX_HOLD_NAVN];
    int hjemmemaal;
    int udemaal;
    int tilskuere;
} kamp;

typedef struct hold {
    char navn[MAX_HOLD_NAVN];
    int point;
    int spillede_kampe;
    int vundne_kampe;
    int vundne_kampe_udebane;
    int vundne_kampe_hjemmebane;
    int tabte_kampe;
    int uafgjorte_kampe;
    int maal_af;
    int maal_mod;
    int samlet_tilskuere;
} hold;

typedef struct runde {
    int nummer;
    int antal_maal;
} runde;

dato lav_dato(const char *);
klokke lav_klokke(const char *);
int klokke_sorre_end(klokke, klokke);
kamp lav_kamp(int, dato, klokke, char[MAX_HOLD_NAVN], char[MAX_HOLD_NAVN],
              int, int, int);

hold lav_hold(const char *);
hold *opret_holdliste(const kamp *);
hold *find_hold(const char *, hold *);
hold farrest_tilskuere(hold *);

void formater_dato(dato, char *);
void formater_tid(klokke, char *);
void opdater_stats(hold *, hold *, const kamp *);
void gennemfor_sason(const kamp *, int, hold *);
runde lav_runde(int, int);
runde *lav_runder(const kamp *, int, int *);
int antal_liner(char *);
int omregn_tilskuer(const char *);
int farrest(const void *, const void *);
int maalrig(const void *, const void *);
int placering(const void *, const void *);


kamp *indlaes_kampe(char *, int *);
kamp *kampe_med_flere_end(int, const kamp *, int, int *);
kamp *kampe_interval(kamp *, int, klokke, klokke, int *);

void udskriv_kamp(kamp);
void udskriv_kamp_header(void);
void udskriv_runde(runde);
void udskriv_maalrige_kampe(const kamp *, int);
void udskriv_maalrig_runde(const runde *, int);
void udskriv_udebane_hold(const hold *);
void udskriv_farrest_tilskuere(hold *);
void udskriv_bestemt_interval(kamp *, int);
void udskriv_kampe_interval(kamp *, int, char *, char *);
void udskriv_tabel(hold *);
void udskriv_hold(hold in);
void udskriv_hold_header(void);

void test(kamp *, int, runde *, int, hold *);
void alle_opgaver(kamp *, int, runde *, int, hold *);

int main(int argc, char *argv[])
{
    int antal_kampe = 0, valg;
    char fra[6], til[6];
    char *input_fil = "superliga-2012-2013";
    kamp *kampe = indlaes_kampe(input_fil, &antal_kampe);
    int antal_runder = 0;
    runde *runder = lav_runder(kampe, antal_kampe, &antal_runder);
    hold *holdliste = opret_holdliste(kampe);
    gennemfor_sason(kampe, antal_kampe, holdliste);

    if (argc == 2) {
        if (strcmp(argv[1], "--print") == 0) {
            alle_opgaver(kampe, antal_kampe, runder, antal_runder,
                         holdliste);
        } else if (strcmp(argv[1], "--test") == 0) {
            test(kampe, antal_kampe, runder, antal_runder, holdliste);
        } else {
            printf("ukendt option: %s\n", argv[1]);
        }
    } else {
        printf("Vælge en opgave 1-6 (eller 0 for at afslutte)> ");

        scanf("%d", &valg);
        while (valg != 0) {
            switch (valg) {
            case 1:
                udskriv_maalrige_kampe(kampe, antal_kampe);
                break;
            case 2:
                udskriv_maalrig_runde(runder, antal_runder);
                break;
            case 3:
                udskriv_udebane_hold(holdliste);
                break;
            case 4:
                udskriv_farrest_tilskuere(holdliste);
                break;
            case 5:
                printf("Skrive fra (hh.mm)> ");
                scanf("%s", &fra[0]);
                printf("Skrive til (hh.mm)> ");
                scanf("%s", &til[0]);
                udskriv_kampe_interval(kampe, antal_kampe, fra, til);
                break;
            case 6:
                udskriv_tabel(holdliste);
                break;
            default:
                printf("Kan ikke finde opgave %d\n", valg);
            }
            printf("Vælge en ny opgave 1-6 (eller 0 for at afslutte)> ");
            scanf("%d", &valg);
        }
        printf("Farvel\n");
    }

    free(holdliste);
    free(runder);
    free(kampe);
    return 0;
}

// input er en dato af formen "dd.mm.aaaa".
dato lav_dato(const char *input)
{
    dato res;
    int dag, maa, aar;
    if (sscanf(input, "%d.%d.%d", &dag, &maa, &aar) != 3) {
        printf("fejl i indlæsning af dato: %s\n", input);
        exit(EXIT_FAILURE);
    }
    res.dag = dag;
    res.maaned = (enum maaned) (maa - 1);
    res.aar = aar;
    return res;
}

// input er et klokkeslæt af formen "hh.mm".
klokke lav_klokke(const char *input)
{
    klokke res;
    int tim, min;
    if (sscanf(input, "%d.%d", &tim, &min) != 2) {
        printf("fejl i indlæsning af klokkeslæt: %s\n", input);
        exit(EXIT_FAILURE);
    }
    res.minutter = min;
    res.timer = tim;

    return res;
}

// returnere en kamp udfra de nødvendige informationer
kamp lav_kamp(int runde, dato dato, klokke klokke,
              char hjemmehold[MAX_HOLD_NAVN], char udehold[MAX_HOLD_NAVN],
              int hjemmemaal, int udemaal, int tilskuere)
{
    kamp res =
        { runde, dato, klokke, "", "", hjemmemaal, udemaal, tilskuere };
    strcpy(res.hjemmehold, hjemmehold);
    strcpy(res.udehold, udehold);
    return res;
}

void formater_dato(dato in, char *out)
{
    if (sprintf(out, "%02d.%02d.%4d", in.dag, (int) in.maaned + 1, in.aar)
        != 10) {
        printf("fejl i formatering af dato: %s\n", out);
        exit(EXIT_FAILURE);
    }
}

void formater_tid(klokke in, char *out)
{
    if (sprintf(out, "%02d:%02d", in.timer, in.minutter) != 5) {
        printf("fejl i formatering af tid: %s\n", out);
        exit(EXIT_FAILURE);
    }
}

void udskriv_kamp(kamp kamp)
{
    char ud_dato[11], ud_tid[6] = "12:00";
    formater_dato(kamp.dato, ud_dato);
    formater_tid(kamp.tid, ud_tid);
    printf("%5d  %s       %s  %3s - %3s %d - %d  %9d\n", kamp.runde,
           ud_dato, ud_tid, kamp.hjemmehold, kamp.udehold, kamp.hjemmemaal,
           kamp.udemaal, kamp.tilskuere);
}

void udskriv_kamp_header(void)
{
    printf("Runde  Dato        Klokkeslæt  Resultat         Tilskuere\n");
}

//laver et tomt hold ud fra et navn
hold lav_hold(const char *navn)
{
    hold res;
    strcpy(res.navn, navn);
    res.point = 0;
    res.spillede_kampe = 0;
    res.vundne_kampe = 0;
    res.vundne_kampe_hjemmebane = 0;
    res.tabte_kampe = 0;
    res.uafgjorte_kampe = 0;
    res.maal_af = 0;
    res.maal_mod = 0;
    res.samlet_tilskuere = 0;
    return res;
}

// laver et array af hold udfra den første runde
hold *opret_holdliste(const kamp * kampe)
{
    hold *holdliste = (hold *) malloc(sizeof(hold) * ANTAL_HOLD);
    if (holdliste == NULL) {
        printf("fejl i tildeling af memory\n");
        exit(EXIT_FAILURE);
    }
    int i, j = 0;

    for (i = 0; i < 6; ++i) {
        holdliste[j++] = lav_hold(kampe[i].hjemmehold);
        holdliste[j++] = lav_hold(kampe[i].udehold);
    }

    return holdliste;
}

hold *find_hold(const char *hold_navn, hold * holdliste)
{
    int i;
    for (i = 0; i < ANTAL_HOLD; ++i) {
        if (strcmp(holdliste[i].navn, hold_navn) == 0) {
            return &holdliste[i];
        }
    }
    printf("kan ikke finde hold: %s\n", hold_navn);
    exit(EXIT_FAILURE);
}

void opdater_stats(hold * hjemmehold, hold * udehold, const kamp * kamp)
{
    hjemmehold->spillede_kampe++;
    hjemmehold->maal_af += kamp->hjemmemaal;
    hjemmehold->maal_mod += kamp->udemaal;
    hjemmehold->samlet_tilskuere += kamp->tilskuere;

    udehold->spillede_kampe++;
    udehold->maal_af += kamp->udemaal;
    udehold->maal_mod += kamp->hjemmemaal;

    if (kamp->hjemmemaal > kamp->udemaal) {
        hjemmehold->vundne_kampe++;
        hjemmehold->vundne_kampe_hjemmebane++;
        hjemmehold->point += 3;
        udehold->tabte_kampe++;
    } else if (kamp->hjemmemaal < kamp->udemaal) {
        udehold->vundne_kampe++;
        udehold->point += 3;
        hjemmehold->tabte_kampe++;
    } else {
        hjemmehold->uafgjorte_kampe++;
        hjemmehold->point++;
        udehold->uafgjorte_kampe++;
        udehold->point++;
    }
}

// går alle kampe i en sæson igennem og giver
void gennemfor_sason(const kamp * kampe, int antal_kampe, hold * holdliste)
{
    int i;
    hold *hjemmehold, *udehold;
    for (i = 0; i < antal_kampe; ++i) {
        hjemmehold = find_hold(kampe[i].hjemmehold, holdliste);
        udehold = find_hold(kampe[i].udehold, holdliste);
        opdater_stats(hjemmehold, udehold, &kampe[i]);
    }
}

runde lav_runde(int nummer, int antal_maal)
{
    runde res;
    res.nummer = nummer;
    res.antal_maal = antal_maal;
    return res;
}

void udskriv_runde(runde in)
{
    printf("Runde #%d, hvor der blev scoret %d mål\n", in.nummer,
           in.antal_maal);
}

runde *lav_runder(const kamp * kampe, int antal_kampe, int *len)
{
    int i;
    int antal_runder = kampe[antal_kampe - 1].runde;
    runde *runder = (runde *) malloc(sizeof(runde) * antal_runder);
    if (runder == NULL) {
        printf("fejl i tildeling af memory\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < antal_runder; ++i) {
        runder[i].nummer = i + 1;
        runder[i].antal_maal = 0;
    }

    for (i = 0; i < antal_kampe; ++i) {
        runder[kampe[i].runde - 1].antal_maal += kampe[i].hjemmemaal;
        runder[kampe[i].runde - 1].antal_maal += kampe[i].udemaal;
    }
    *len = antal_runder;
    return runder;
}

// tæller antallet af linjer i fil
int antal_liner(char *fil)
{
    char linje[MAX_LENJE_LENGDE];
    int res = 0;
    FILE *in = fopen(fil, "r");
    if (in == NULL) {
        printf("fejl i åbning af filen: %s\n", fil);
        exit(EXIT_FAILURE);
    }

    while (fgets(linje, MAX_LENJE_LENGDE, in) != NULL
           && strcmp(linje, "") != 0) {
        res++;
    }

    fclose(in);
    return res;
}

// Omregner et tilskure antal med tusinde separator (.) til et hel tal.
// Virker kun for tal minde end 1.000.000
int omregn_tilskuer(const char *input)
{
    int fir, sec;
    int scan_res = sscanf(input, "%d.%d", &fir, &sec);
    if (scan_res == 2) {
        return fir * 1000 + sec;
    } else if (scan_res == 1) {
        return fir;
    } else {
        printf("fejl i læsning a tilskuretal: %s\n", input);
        exit(EXIT_FAILURE);
    }
}

// indlæser en kamp fra filen input retunere et array af kampe.
// størelsen af arrayet bliver skrevet til len
kamp *indlaes_kampe(char *input, int *len)
{
    int antal_kampe = antal_liner(input);
    FILE *in = fopen(input, "r");
    if (in == NULL) {
        printf("fejl i åbning af filen: %s\n", input);
        exit(EXIT_FAILURE);
    }

    kamp *kampe = (kamp *) malloc(sizeof(kamp) * antal_kampe);
    if (kampe == NULL) {
        printf("fejl i tildeling af memory\n");
        exit(EXIT_FAILURE);
    }

    int i, runde, hjemmemaal, udemaal, tilskuere;
    dato dato;
    klokke klokke;
    char hjemmehold[MAX_HOLD_NAVN], udehold[MAX_HOLD_NAVN],
        dato_streng[15], klokke_streng[10], tilskuere_streng[10];

    for (i = 0; i < antal_kampe; ++i) {
        if (fscanf(in, " %d %s kl. %s %s - %s %d - %d %s ",
                   &runde, dato_streng, klokke_streng, hjemmehold, udehold,
                   &hjemmemaal, &udemaal, tilskuere_streng) != 8) {
            printf("fejl i indlæsning af kamp %d\n", i + 1);
            exit(EXIT_FAILURE);
        }

        dato = lav_dato(dato_streng);
        klokke = lav_klokke(klokke_streng);
        tilskuere = omregn_tilskuer(tilskuere_streng);

        kampe[i] = lav_kamp(runde, dato, klokke, hjemmehold, udehold, hjemmemaal,
                            udemaal, tilskuere);
    }

    fclose(in);
    *len = antal_kampe;
    return kampe;
}

// køre test af div functioner
void test(kamp * kampe, int antal_kampe, runde * runder, int antal_runder,
          hold * holdliste)
{
    assert(antal_kampe == 198);
    assert(strcmp(kampe[0].hjemmehold, "AGF") == 0);
    assert(strcmp(kampe[antal_kampe - 1].udehold, "AGF") == 0);
    assert(kampe[2].runde == 1);
    assert(kampe[37].hjemmemaal == 2);
    assert(kampe[37].udemaal == 3);
    assert(kampe[149].dato.maaned == april);
    assert(kampe[99].tid.timer == 17);
    assert(kampe[159].tilskuere == 0);
    assert(kampe[160].tilskuere == 7624);

    assert(antal_runder = 33);
    assert(runder[0].nummer = 1);
    assert(runder[1].antal_maal = 12);
    assert(runder[antal_runder - 1].antal_maal = 19);

    assert(strcmp(holdliste[0].navn, "AGF") == 0);
    assert(strcmp(holdliste[11].navn, "FCN") == 0);
    assert(holdliste[0].vundne_kampe == 11);
    assert(holdliste[5].samlet_tilskuere == 50394);
    assert(holdliste[8].maal_af == 62);
    assert(holdliste[11].point == 60);
    printf("Alle tests færdige\n");
}

kamp *kampe_med_flere_end(int maal, const kamp * kampe, int antal_kampe,
                          int *out_len)
{
    int i, res_counter = 0;
    kamp *res = (kamp *) malloc(sizeof(kamp) * antal_kampe);
    if (res == NULL) {
        printf("fejl i tildeling af memory\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < antal_kampe; ++i) {
        if (kampe[i].hjemmemaal + kampe[i].udemaal >= maal) {
            res[res_counter++] = kampe[i];
        }
    }
    *out_len = res_counter;
    return res;
}

void udskriv_maalrige_kampe(const kamp * kampe, int antal_kampe)
{
    kamp *maalrige_kampe;
    int antal_maalrige_kampe, i;

    maalrige_kampe = kampe_med_flere_end(7, kampe, antal_kampe, &antal_maalrige_kampe);

    printf("Opgave 1\n");
    printf("Kampe, hvor der er scoret syv eller flere mål:\n");
    udskriv_kamp_header();
    for (i = 0; i < antal_maalrige_kampe; ++i) {
        udskriv_kamp(maalrige_kampe[i]);
    }
    printf("\n");

    free(maalrige_kampe);
}

runde find_maalrig_runde(const runde * runder, int antal_runder)
{
    int i, maal = 0, maal_id = 0;
    for (i = 0; i < antal_runder; ++i) {
        if (runder[i].antal_maal > maal) {
            maal_id = i;
            maal = runder[i].antal_maal;
        }
    }
    return runder[maal_id];
}

void udskriv_maalrig_runde(const runde * runder, int antal_runder)
{
    printf("Opgave 2\n");
    printf("Den mest målrige runde i turneringen:\n");
    runde maalrig = find_maalrig_runde(runder, antal_runder);
    udskriv_runde(maalrig);
    printf("\n");
}

hold *udebane_hold(const hold * holdliste, int *antal_udebane)
{
    int i, hjemme, ude, ialt, res_counter = 0;
    hold *res = (hold *) malloc(sizeof(hold) * ANTAL_HOLD);
    if (res == NULL) {
        printf("fejl i tildeling af memory\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < ANTAL_HOLD; ++i) {
        hjemme = holdliste[i].vundne_kampe_hjemmebane;
        ialt = holdliste[i].vundne_kampe;
        ude = ialt - hjemme;
        if (ude > hjemme) {
            res[res_counter++] = holdliste[i];
        }
    }
    *antal_udebane = res_counter;
    return res;
}

void udskriv_udebane_hold(const hold * holdliste)
{
    printf("Opgave 3\n");
    printf("Hold, som vinder flere kampe på udebane end på hjemmebane:\n");
    int antal_udebane = 0, i;
    hold *udebane = udebane_hold(holdliste, &antal_udebane);

    for (i = 0; i < antal_udebane; ++i) {
        printf("%s\n", udebane[i].navn);
    }
    printf("\n");
    free(udebane);
}

int farrest(const void *e1, const void *e2)
{
    hold *h1 = (hold *) e1;
    hold *h2 = (hold *) e2;
    return h1->samlet_tilskuere - h2->samlet_tilskuere;
}

hold farrest_tilskuere(hold * holdliste)
{
    qsort(holdliste, ANTAL_HOLD, sizeof(hold), farrest);
    return holdliste[0];
}

void udskriv_farrest_tilskuere(hold * holdliste)
{
    printf("Opgave 4\n");
    printf("Det hold der har haft færrest tilskuere ved kampe, som spilles på klubbens hjemmebane:\n");
    hold farrest = farrest_tilskuere(holdliste);
    printf("%s har kun haft %d tilskuere i alt\n", farrest.navn, farrest.samlet_tilskuere);
    printf("\n");
}

void udskriv_bestemt_interval(kamp * kampe, int antal_kampe)
{
    printf("Opgave 5\n");
    udskriv_kampe_interval(kampe, antal_kampe, "12.05", "13.10");
    printf("\n");
}

void udskriv_kampe_interval(kamp * kampe, int antal_kampe, char *fra,
                            char *til)
{
    kamp *kampe_i_interval;
    int antal_kampe_interval, i;

    klokke fra_k = lav_klokke(fra);
    klokke til_k = lav_klokke(til);
    kampe_i_interval = kampe_interval(kampe, antal_kampe, fra_k, til_k,
                       &antal_kampe_interval);

    if (antal_kampe_interval == 0) {
        printf("Ingen kampe fundet mellem %s og %s\n", fra, til);
    } else {
        printf("Kampe der startes mellem kl. %s og %s:\n", fra, til);
        qsort(kampe_i_interval, antal_kampe_interval, sizeof(kamp), maalrig);
        udskriv_kamp_header();
        for (i = 0; i < antal_kampe_interval; ++i) {
            udskriv_kamp(kampe_i_interval[i]);
        }
    }
    free(kampe_i_interval);
}

int maalrig(const void *e1, const void *e2)
{
    kamp *k1 = (kamp *) e1;
    kamp *k2 = (kamp *) e2;
    return (k2->hjemmemaal + k2->udemaal) - (k1->hjemmemaal + k1->udemaal);
}

kamp *kampe_interval(kamp * kampe, int antal_kampe, klokke fra, klokke til,
                     int *len)
{
    int i, res_counter = 0;
    kamp *res = (kamp *) malloc(sizeof(kamp) * antal_kampe);
    if (res == NULL) {
        printf("fejl i tildeling af memory\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < antal_kampe; ++i) {
        if (klokke_sorre_end(kampe[i].tid, fra)
            && klokke_sorre_end(til, kampe[i].tid)) {
            res[res_counter++] = kampe[i];
        }
    }
    *len = res_counter;
    return res;
}

int klokke_sorre_end(klokke k1, klokke k2)
{
    if (k1.timer != k2.timer) {
        return k1.timer >= k2.timer;
    } else {
        return k1.minutter >= k2.minutter;
    }
}

void udskriv_tabel(hold * holdliste)
{
    int i;
    printf("Opgave 6\n");
    printf("Samlet tabel over stillingen i turneringen efter sidste spillerunde:\n");

    qsort(holdliste, ANTAL_HOLD, sizeof(hold), placering);

    udskriv_hold_header();
    for (i = 0; i < ANTAL_HOLD; ++i) {
        udskriv_hold(holdliste[i]);
    }
    printf("\n");
}

void udskriv_hold(hold in)
{
    int maalforskel = in.maal_af - in.maal_mod;
    printf("%3s %7d %5d %6d %5d %9d %+10d\n", in.navn, in.point,
           in.spillede_kampe, in.vundne_kampe, in.tabte_kampe,
           in.uafgjorte_kampe, maalforskel);
}

int placering(const void *e1, const void *e2)
{
    hold *h1 = (hold *) e1;
    hold *h2 = (hold *) e2;
    int h1_maalforskel = h1->maal_af - h1->maal_mod;
    int h2_maalforskel = h2->maal_af - h2->maal_mod;

    if (h1->point != h2->point) {
        return h2->point - h1->point;
    } else if (h1_maalforskel != h2_maalforskel) {
        return h2_maalforskel - h1_maalforskel;
    } else if (h1->maal_af != h2->maal_af) {
        return h2->maal_af - h1->maal_af;
    } else {
        return strcmp(h1->navn, h2->navn);
    }
}

void udskriv_hold_header(void)
{
    printf("Navn Points Kampe Vundne Tabte Uafgjorte Målforskel\n");
}

void alle_opgaver(kamp * kampe, int antal_kampe, runde * runder,
                  int antal_runder, hold * holdliste)
{
    printf("Printer alle opgaver\n\n");
    udskriv_maalrige_kampe(kampe, antal_kampe);
    udskriv_maalrig_runde(runder, antal_runder);
    udskriv_udebane_hold(holdliste);
    udskriv_farrest_tilskuere(holdliste);
    udskriv_bestemt_interval(kampe, antal_kampe);
    udskriv_tabel(holdliste);
}
