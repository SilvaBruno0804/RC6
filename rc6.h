#ifndef RC6_H
#define RC6_H

#include <stdint.h>

#define ROUNDS      20
#define KEY_LENGTH  256
#define W           32

typedef struct rc6_ctx
{
    uint8_t r;
    uint32_t *S;
} rc6_ctx_t;


rc6_ctx_t* ak_rc6_ctx_create_new();


void ak_rc6_ctx_free(rc6_ctx_t *ctx);


void ak_rc6_ctx_key_schedule(rc6_ctx_t *ctx, void *key);


void ak_rc6_ctx_encrypt(rc6_ctx_t *ctx, void *block);


void ak_rc6_ctx_decrypt(rc6_ctx_t *ctx, void *block);

#endif // RC6_H

