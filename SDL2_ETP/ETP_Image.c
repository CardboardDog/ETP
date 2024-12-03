#include<SDL2_ETP/ETP_Image.h>

SDL_Texture* ETP_LoadTexture(SDL_Renderer* renderer, const char* file){
    etp_base* etp_img = etp_create_base();
    
    if(etp_loads(etp_img,file)){
        etp_free(etp_img);
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        etp_img->w,
        etp_img->h
    );

    unsigned char r,g,b,a;
    SDL_GetRenderDrawColor(renderer,&r,&g,&b,&a);
    SDL_SetRenderTarget(renderer,texture);
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);

    for(int y=0;y<etp_img->h;y++){
        for(int x=0;x<etp_img->w;x++){
            int pos = (x+(y*etp_img->w))*4;
            if(etp_img->p[pos+3]){
                SDL_SetRenderDrawColor(
                    renderer,
                    etp_img->p[pos],
                    etp_img->p[pos+1],
                    etp_img->p[pos+2],
                    etp_img->p[pos+3]
                );
                SDL_RenderDrawPoint(renderer,x,y);
            }
        }
    }

    SDL_SetRenderTarget(renderer,NULL);
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
    etp_free(etp_img);

    return texture;
}