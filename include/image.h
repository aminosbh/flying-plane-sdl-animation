/*
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "utils.h"

struct Image
{
    // Loaded texture
    SDL_Texture *texture;

    // Original width and height
    int w, h;

    // Current coordinates, width and height
    SDL_Rect rect;
};
typedef struct Image Image;


bool Image_load(SDL_Renderer *renderer, Image *image, const char *file);
void Image_destroy(Image *image);

void Image_render(SDL_Renderer *renderer, Image *image);
void Image_renderCrop(SDL_Renderer *renderer, Image *image, SDL_Rect *crop, SDL_Point *pos);

#endif // IMAGE_H
