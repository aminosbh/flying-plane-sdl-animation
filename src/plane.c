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

#include "plane.h"

bool Plane_load(SDL_Renderer *renderer, Plane *plane, const char *image, const char *shadow)
{
    // Load plane image
    if(!Image_load(renderer, &plane->image, image))
    {
        return false;
    }

    // Load plane shadow
    if(!Image_load(renderer, &plane->shadow, shadow))
    {
        Image_destroy(&plane->image);
        return false;
    }

    return true;
}

void Plane_destroy(Plane *plane)
{
    Image_destroy(&plane->image);
    Image_destroy(&plane->shadow);
}

void Plane_setX(Plane *plane, int x)
{
    // Plane x coordinate
    plane->image.rect.x = x;

    // Plane shadow x coordinate
    plane->shadow.rect.x = plane->image.rect.x
                            + (plane->image.rect.w - plane->shadow.rect.w) / 2
                            + plane->shadowOffset.x;
}

void Plane_setY(Plane *plane, int y)
{
    // Plane y coordinate
    plane->image.rect.y = y;

    // Plane shadow y coordinate
    plane->shadow.rect.y = plane->image.rect.y
                            + (plane->image.rect.h - plane->shadow.rect.h) / 2
                            + plane->shadowOffset.y;
}

void Plane_setCoordinates(Plane *plane, int x, int y)
{
    Plane_setX(plane, x);
    Plane_setY(plane, y);
}

void Plane_moveX(Plane *plane, int x)
{
    Plane_setX(plane, plane->image.rect.x + x);
}

void Plane_moveY(Plane *plane, int y)
{
    Plane_setY(plane, plane->image.rect.y + y);
}

void Plane_setDirection(Plane *plane, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        plane->direction &= ~DIRECTION_DOWN;
        plane->direction |= DIRECTION_UP;
        break;

    case SDLK_DOWN:
        plane->direction &= ~SDLK_UP;
        plane->direction |= DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        plane->direction &= ~SDLK_LEFT;
        plane->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        plane->direction &= ~DIRECTION_RIGHT;
        plane->direction |= DIRECTION_LEFT;
        break;
    }
}

void Plane_unsetDirection(Plane *plane, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        plane->direction &= ~DIRECTION_UP;
        break;

    case SDLK_DOWN:
        plane->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        plane->direction &= ~DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        plane->direction &= ~DIRECTION_LEFT;
        break;
    }
}

void Plane_render(SDL_Renderer *renderer, Plane *plane)
{
    // Render plane shadow
    Image_render(renderer, &plane->shadow);

    // Render plane
    Image_render(renderer, &plane->image);
}

void Plane_move(Plane *plane, int screenWidth, int screenHeight, int framerate)
{
    int planeStep = plane->speed / framerate;

    if( (plane->direction & DIRECTION_UP)
            && plane->image.rect.y - planeStep >= plane->margin)
    {
        Plane_moveY(plane, -planeStep);
    }
    else if( (plane->direction & DIRECTION_DOWN)
             && plane->image.rect.y + plane->image.rect.h + planeStep <= screenHeight - plane->margin)
    {
        Plane_moveY(plane, planeStep);
    }

    if( (plane->direction & DIRECTION_RIGHT)
            && plane->image.rect.x + plane->image.rect.w + planeStep <= screenWidth - plane->margin)
    {
        Plane_moveX(plane, planeStep);
    }
    else if( (plane->direction & DIRECTION_LEFT)
             && plane->image.rect.x - planeStep >= plane->margin)
    {
        Plane_moveX(plane, -planeStep);
    }
}
