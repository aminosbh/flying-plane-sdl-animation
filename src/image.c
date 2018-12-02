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

#include "image.h"

bool Image_load(SDL_Renderer *renderer, Image *image, const char *file)
{
    // Load image
    image->texture = IMG_LoadTexture(renderer, file);
    if(!image->texture)
    {
        printf("Unable to load image '%s'!\n"
               "SDL_image Error: %s", file, IMG_GetError());
        return false;
    }

    // Get dimensions
    SDL_QueryTexture(image->texture, NULL, NULL, &image->w, &image->h);

    image->rect.w = image->w;
    image->rect.h = image->h;

    return true;
}

void Image_destroy(Image *image)
{
    SDL_DestroyTexture(image->texture);
    memset(image, 0, sizeof(Image));
}

void Image_render(SDL_Renderer *renderer, Image *image)
{
    SDL_RenderCopy(renderer, image->texture, NULL, &image->rect);
}

void Image_renderCrop(SDL_Renderer *renderer, Image *image, SDL_Rect *crop, SDL_Point *pos)
{
    SDL_Rect rect = image->rect;
    rect.w = crop->w;
    rect.h = crop->h;

    if(pos)
    {
        rect.x = pos->x;
        rect.y = pos->y;
    }

    SDL_RenderCopy(renderer, image->texture, crop, &rect);
}
