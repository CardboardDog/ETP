#include<etp.h>
#include<stdio.h>
#ifndef NO_SDL2
#include<SDL2/SDL.h>
#endif
int main(){
    etp_base* my_image = etp_create_base();
    etp_base* my_image2 = etp_create_base();
    etp_base* bad_etp = etp_create_base();
    FILE* my_etp = fopen("etp.etp","r");
    etp_result error = etp_load(my_image,my_etp);
    if(error)
        etp_print_error(error);
    if(my_etp)
        fclose(my_etp);
    error = etp_loads(my_image2,"etp.etp");
    if(error)
        etp_print_error(error);
    error = etp_loads(bad_etp,"etp.png");
    if(error)
        etp_print_error(error);
#ifndef NO_SDL2
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("ETPP demo",0,0,510,255,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer,0,15,0,255);
    SDL_RenderClear(renderer);
    for(int y=0;y<my_image->h;y++){
        for(int x=0;x<my_image->w;x++){
            int pos = (x+(y*my_image->w))*4;
            if(my_image->p[pos+3]){
                SDL_SetRenderDrawColor(renderer,my_image->p[pos],my_image->p[pos+1],my_image->p[pos+2],my_image->p[pos+3]);
                SDL_RenderDrawPoint(renderer,x,y);
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    SDL_Quit();
#endif
    etp_free(my_image);
    etp_free(my_image2);
    etp_free(bad_etp);
    return 0;
}