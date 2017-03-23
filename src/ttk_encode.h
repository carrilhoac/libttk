
#ifndef TTK_ENCODE_H
#define TTK_ENCODE_H

#ifndef TTK_H
#error Yout must include 'ttk.h' before 'ttk_encode.h'
#endif

#ifdef __cplusplus
extern "C" {
#endif

TtkBuffer*   Ttk_BufEncZlibEx (const TtkBuffer* buf,
                int encode_level, int encode_strategy);

TtkBuffer*   Ttk_BufDecZlibEx (const TtkBuffer* buf,
                int decode_level, int decode_strategy, uint64_t decode_size);

TtkBuffer*   Ttk_BufEncLZMA (const TtkBuffer* buf);
TtkBuffer*   Ttk_BufDecLZMA (const TtkBuffer* buf);

TtkBuffer*   Ttk_BufEncBzip2 (const TtkBuffer* buf);
TtkBuffer*   Ttk_BufDecBzip2 (const TtkBuffer* buf);

TtkBuffer*   Ttk_BufEncQLZ (const TtkBuffer* buf);
TtkBuffer*   Ttk_BufDecQLZ (const TtkBuffer* buf);

#define TTK_ENCALGO_NONE     0
#define TTK_ENCALGO_ZLIB     1
#define TTK_ENCALGO_LZMA     2
#define TTK_ENCALGO_BZIP2    3
#define TTK_ENCALGO_QLZ      4

typedef struct {
    TtkBuffer *enc_buf;
    TtkBuffer *dec_buf;
    uint8_t   encoded;    /* Encoded = 1 or Decoded = 0 */
    uint8_t   algorithm;  /* Unknown, none, zlib, QLZ, bzip2, LZMA, ... */
    uint8_t   level;
    uint8_t   strategy;
} TtkEncode;

TtkEncode* Ttk_CtxAlloc (void);
void Ttk_CtxFree (TtkEncode* ctx);

int Ttk_CtxEncZlib (TtkEncode* ctx);
int Ttk_CtxDecZlib (TtkEncode* ctx);

#ifdef __cplusplus
}
#endif
#endif /* !TTK_ENCODE_H */
