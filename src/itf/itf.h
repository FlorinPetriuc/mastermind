/*
 * Copyright (C) 2018 Florin Petriuc. All rights reserved.
 * Initial release: Florin Petriuc <petriuc.florin@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#ifndef _ITF_H_
#define _ITF_H_

void itf_init();
void itf_clear();

char *itf_ask(const char *pattern, ...);
void itf_error(const char *pattern, ...);
void itf_show(const char *pattern, ...);

#endif