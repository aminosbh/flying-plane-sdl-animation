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

#include "background.h"

bool Background_load(SDL_Renderer *renderer, Background *background, const char *file)
{
    return Image_load(renderer, &background->image, file);
}

void Background_destroy(Background *background)
{
    Image_destroy(&background->image);
}

void Background_move(Background *background, int framerate)
{
    background->image.rect.y += background->speed / framerate;
    if(background->image.rect.y >= background->image.rect.h)
        background->image.rect.y = background->image.rect.y - background->image.rect.h;
}


void Background_render(SDL_Renderer *renderer, Background *background, int width, int height)
{
    SDL_Rect crop = background->image.rect;

    if(background->direction == DIRECTION_DOWN)
    {
        if(background->image.rect.y < height)
        {
            crop.y = 0;
            crop.h = background->image.rect.h - background->image.rect.y;

            SDL_Point pos = { 0, background->image.rect.y };
            Image_renderCrop(renderer, &background->image, &crop, &pos);
        }

        if(background->image.rect.y != 0)
        {
            crop.y = background->image.rect.h - background->image.rect.y;
            crop.h = MIN(background->image.rect.y, height);

            SDL_Point pos = { 0, 0 };
            Image_renderCrop(renderer, &background->image, &crop, &pos);
        }
    }
}
