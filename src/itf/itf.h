#ifndef _ITF_H_
#define _ITF_H_

void itf_init();
void itf_clear();

char *itf_ask(const char *pattern, ...);
void itf_error(const char *pattern, ...);
void itf_show(const char *pattern, ...);

#endif