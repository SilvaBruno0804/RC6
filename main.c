#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rc6.h"

void encrypt(unsigned char *key, unsigned char *txt, unsigned int len, rc6_ctx_t *p)
{
//    ak_rc6_ctx_key_schedule(p,key);
    for(int i = 0;  i < len; i+=16){
        ak_rc6_ctx_encrypt(p, txt+i);
    }
    //printf("%s\n\n\n", txt);
}
void decrypt(unsigned char *key, unsigned char *txt, unsigned int len, rc6_ctx_t *p){
    //rc6_ctx_t *p = ak_rc6_ctx_create_new();
    //ak_rc6_ctx_key_schedule(p,key);
    for(int i = 0;  i < len; i+=16){
        ak_rc6_ctx_decrypt(p, txt+i);
    }
   //printf("%s\n\n\n", txt);
}

int main(void)
{
    rc6_ctx_t *p = ak_rc6_ctx_create_new();
    FILE *fpSourceFile = fopen("C:\\Users\\bruno\\pictures\\teste.txt", "rb");
    FILE *fpTargetFileCipher = fopen("C:\\Users\\bruno\\Pictures\\cifrado.txt", "wb");
    FILE *fpTargetFile = fopen("C:\\Users\\bruno\\Pictures\\output.txt", "wb");
    unsigned int cont = 0;
    char cTemp;
    unsigned char *txt1 = malloc(40000000);
    unsigned char key1[32] = {0xFF}; /// 256 bits
    ak_rc6_ctx_key_schedule(p,key1);

   //Se não achou o arquivo retorna erro
    if(fpSourceFile == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    //Lê cada byte do arquivo
    while(fread(&cTemp, 1, 1, fpSourceFile) == 1)
    {
        txt1[cont] = cTemp;
        cont++;
    }
    encrypt(key1, txt1, cont, p);

    for(int i = 0; i < cont; i++){
        fwrite(&txt1[i], 1, 1, fpTargetFileCipher);
    }


    decrypt(key1, txt1, cont, p);



    for(int i = 0; i < cont; i++){
        fwrite(&txt1[i], 1, 1, fpTargetFile);
    }
    free(txt1);
    return 0;
}
