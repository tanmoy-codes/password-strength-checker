#include<stdio.h>
#include<string.h>
int checkUpperCaseLetter( char password[] ){                           // counting number of upper case letters
    int i = 0;
    int A = 0;
    while( password[i] != '\0'){
        if( password[i] >= 'A' && password[i] <= 'Z'){
            A++;
        }
        i++;
    }
    return A;
}
int checkLowerCaseLetter( char password[] ){                         // counting number of lower case letters
    int i = 0;
    int a = 0;
    while( password[i] != '\0'){
        if( password[i] >= 'a' && password[i] <= 'z'){
            a++;
        }
        i++;
    }
    return a;
}

int CheckNumber( char password[] ){                                //counting number of numbers
    int i = 0;
    int N = 0;
    while( password[i] != '\0'){
        if( password[i] >= '0' && password[i] <= '9'){
            N++;
        }
        i++;
    }
    return N;

}

int CheckSpecial( char password[] ){                                // giving score to special characters
    int i = 0;
    int s = 0;
    while(password[i] != '\0'){
        if( !(password[i] >= 'A' && password[i] <= 'Z') && !( password[i] >= 'a' && password[i] <= 'z') && !( password[i] >= '0' && password[i] <= '9')){
            s++;
        }
        i++;
    }
    return s;
}



void StrengthReview( int score ){                                     // reviewing the password
    if(score <= 10){
        printf("==== PASSWORD STRENGTH : VERY WEAK ====\n\n");
    }
    else if(score >= 11 && score <= 20){
        printf("==== PASSWORD STRENGTH : WEAK ====\n\n");
    }
    else if(score >= 21 && score <= 35){
        printf("==== PASSWORD STRENGTH : MODERATE ====\n\n");
    }
    else if(score >= 36 && score <= 55){
        printf("==== PASSWORD STRENGTH : STRONG ====\n\n");
    }
    else if( score >= 56){
        printf("==== PASSWORD STRENGTH : VERY STRONG ====\n\n");
    }
    return;
}

int CheckRepetition( char password[]){                                 // checking for repeatitions
    int r = 0;          // totalr : total number of repetations
    int i = 1;                                                         // because, i = 0 will create distrubance while password[0]  
    while(password[i] != '\0'){
        if( password[i] == password[i-1]){
            r++;
        }
        i++;
    }
    return r;
}

int CommonWords( char password[] ){                                   // checking for common words
    if(strcmp(password, "password") == 0) return 1;
    else if(strcmp(password, "Password") == 0) return 1;
    else if(strcmp(password, "PASSWORD") == 0) return 1;
    else if(strcmp(password, "123456") == 0) return 1;
    else if(strcmp(password, "12345678") == 0) return 1;
    else if(strcmp(password, "123456789") == 0) return 1;
    else if(strcmp(password, "1234567890") == 0) return 1;
    else if(strcmp(password, "qwerty") == 0) return 1;
    else if(strcmp(password, "qwerty123") == 0) return 1;
    else if(strcmp(password, "abc123") == 0) return 1;
    else if(strcmp(password, "abcdef") == 0) return 1;
    else if(strcmp(password, "admin") == 0) return 1;
    else if(strcmp(password, "administrator") == 0) return 1;
    else if(strcmp(password, "welcome") == 0) return 1;
    else if(strcmp(password, "welcome123") == 0) return 1;
    else if(strcmp(password, "letmein") == 0) return 1;
    else if(strcmp(password, "login") == 0) return 1;
    else if(strcmp(password, "guest") == 0) return 1;
    else if(strcmp(password, "root") == 0) return 1;
    else if(strcmp(password, "passw0rd") == 0) return 1;
    else if(strcmp(password, "password123") == 0) return 1;
    else return 0;
}

int main(){
    printf("\n==== LET'S CHECK THE STRENGTH OF YOUR PASSWORD ====\n\n");
    printf("Enter your password : ");
    char password[100];
    scanf("%99s", password);

    int length = strlen(password);                                    // checking length od password

    int UCL = checkUpperCaseLetter(password);                         // counting number of upper case letters , UCL = Upper Case Letter

    int LCL = checkLowerCaseLetter(password);                         // counting number of lower case letters , LCL = Lower Case Letter

    int number = CheckNumber(password);                               //counting number of numbers

    int special = CheckSpecial(password);                             //counting number of special characters


    int score = 0;
    
    if(length > 20) score += 15;
    else if(length > 15) score += 10;
    else if(length >= 10) score += 5;
    else if(length < 10) score += 2;

    if(UCL > 16) score += 20;
    else if(UCL > 12) score += 15;
    else if(UCL > 8) score += 10;
    else if(UCL >= 4) score += 5;
    else if(UCL < 4) score += 2;

    if(LCL > 16) score += 20;
    else if(LCL > 12) score += 15;
    else if(LCL > 8) score += 10;
    else if(LCL >= 4) score += 5;
    else if(LCL < 4) score += 2;

    if(number > 16) score += 20;
    else if(number > 12) score += 15;
    else if(number > 8) score += 10;
    else if(number >= 4) score += 5;
    else if(number < 4) score += 2;

    if(special > 10) score += 30;
    else if(special > 8) score += 20;
    else if(special > 6) score += 15;
    else if(special >= 2) score += 10;
    else if(special < 2) score += 5;

    int repeat = CheckRepetition(password);                             // checking for repeatitions
    if(repeat > 6){
        printf("==== WARNING !! ====\n");
        printf("==== YOUR INPUT HAS MULTIPLE REPETITIONS, THIS CAN'T BE TAKEN AS A PASSWORD ====\n\n");
        printf("==== PASSWORD STRENGTH : VERY WEAK ====\n");
        return 0;
    }
    else if(repeat > 3) score -= 10;

    if(CommonWords(password)){                                       // checking for common words, if(1) = true and if(0) = false
        printf("==== COMMON PASSWORD DETECTED !! ====\n\n==== YOUR PASSWORD IS WEAK ====");
        return 0;
    }

    printf("\n\nScore = %d\n\n", score);

    StrengthReview(score);                                            // reviewing the password

    return 0;
}