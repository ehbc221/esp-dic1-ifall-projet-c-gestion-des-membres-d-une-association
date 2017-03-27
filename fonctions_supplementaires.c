/*************************************************
*     Déclaration des bibliothèques requises     *
*************************************************/
// Fonctions des bibliothèques standard + Constantes
#include "entetes.h"
// Fonctions supplémentaires de l'application
#include "fonctions_supplementaires.h"
/**********************************************************************
*     Définition des fonctions "supplémentaires" de l'application     *
**********************************************************************/
// Corriger quelques problèmes liés à l'utilisation de la fonction fgets soit en enlevant le retour a la ligne (après une saisie correcte c-a-d terminée par "entrée"), soit en enlevant les caractères restants dans le buffer (après une saisie incorrecte c-a-d terminée dépassement de la taille de la chaine, ou erreur interne)
void enleverCaracteresRestants(char *chaine)
{
    // On cherche le caractère de retour à la ligne "\n"
    char *p = strchr(chaine, '\n');
    // Si on le trouve, on annule sa valeur
    if (p) {
        *p = '\0';
    }
    // Sinon : cas où la dernière saisie ne s'est pas déroulée correctement (ou on a dépassé le nombre de caractères max spécifié en deuxième argument) alors la seconde saisie va contenir les caractères qui n'ont pas été lus
    else {
        enleverCaracteresSuperflus();
    }
}
// Enlever les caractères restants dans le buffer (après une saisie incorrecte c-a-d terminée dépassement de la taille de la chaine, ou erreur interne)
void enleverCaracteresSuperflus(void)
{
    int c;
    // Lire tous les caractères restant dans le buffer le buffer s'il reste des caractères non lus
    while ((c = getchar()) != '\n' && c != EOF) {}
}
// Vérifier si une chaine de caractères est alphanumérique ou non
int estAlphaNumerique(char *chaine)
{
    int i, status_alpha_numerique=SUCCES, taille_chaine = strlen(chaine);
    // Pour chaque caractere de la chaine
    for (i=0; i<taille_chaine; i++) {
        // Si ce n'est ni une lettre alphabétique, ni un chiffre, ni un espace, retourner ECHEC
        if (!isdigit(chaine[i]) && !isalpha(chaine[i]) && !isspace(chaine[i])) {
            return status_alpha_numerique = ECHEC;
        }
    }
    return status_alpha_numerique;
}
// Vérifier si une chaine de caractères est alphabétique ou non
int estAlphabetique(char *chaine)
{
    int i, status_alphabetique=SUCCES, taille_chaine = strlen(chaine);
    // Pour chaque caractere de la chaine
    for (i=0; i<taille_chaine; i++) {
        // Si ce n'est pas une lettre alphabétique, retourner ECHEC
        if (!isalpha(chaine[i]) && !isspace(chaine[i])) {
            return status_alphabetique = ECHEC;
        }
    }
    return status_alphabetique;
}
// Vérifier si une chaine de caractères est numérique ou non (>0)
int estNumerique(char *chaine)
{
    int i, status_numerique=SUCCES, taille_chaine = strlen(chaine);
    // Pour chaque caractere de la chaine
    for (i=0; i<taille_chaine; i++) {
        // Si ce n'est pas un chiffre, retourner ECHEC
        if (!isdigit(chaine[i])) {
            return status_numerique = ECHEC;
        }
    }
    return status_numerique;
}
// Vérifier si une chaine de caractères est une année scolaire valide ou non
int estAnneeScolaireValide(char *chaine)
{
    int i, status_annee_scolaire=SUCCES, taille_chaine = strlen(chaine);
    // Si la taille est differente de 9 (), retourner 0
    if (taille_chaine != 9) {
        status_annee_scolaire = ECHEC;
        return status_annee_scolaire;
    }
    // Si le caractère séparateur est different de /, retourner 0
    if (chaine[4] != '/') {
        status_annee_scolaire = ECHEC;
        return status_annee_scolaire;
    }
    // Pour chaque caractere de la chaine (à part le séparateur)
    for (i=0; i<taille_chaine && i!= 4; i++) {
        // Si ce n'est pas un chiffre, retourner 0
        if (!isdigit(chaine[i])) {
            status_annee_scolaire = ECHEC;
            return status_annee_scolaire;
        }
    }
    // Sinon, retourner 1
    return status_annee_scolaire;
}
// Nettoyer l'écran (effacer tout son contenu). Alternative à system("cls") sous windows, ou system("clear") sous linux
void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
