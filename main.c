//Music Player made by CG64 - 2021
//I just used SDL_mixer to play musics

#include <stdio.h>
#include <SDL_mixer.h>
#include <string.h>
#include <stdbool.h>
#include <SDL.h>

//Music pointer
Mix_Music *music = NULL;

bool init(){

    //success flag
    bool success = true;


    //Init SDL2
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Could not init SDL2! Error: %s", SDL_GetError());
        success = false;
    }

    //Init SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        printf("Could not init SDL2 mixer! Error: %s", Mix_GetError());
        success = false;
    }

    return success;
}

void close_program(){
    Mix_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[]){

    //Variables and constants
    char name[100]; //Music name that I want to play
    char input; //Input handle
    bool close = false; //Flag made for close the program

    //Init everything related to SDL2 and SDL2_mixer
    if (init() == 0){
        printf("Failed to init SDL2 mixer. Closing program...");
        return 0;
    }

    //Ask to user write a music name to play
    printf("Write a music name that you want\nExample: Musics/Meadow-Match.mp3\n");
    gets(name);

    //Loads a music
    printf("loading %s...\n", name);
    music = Mix_LoadMUS(name);
    printf("Type P to play or pause\nType S to stop playing and/or change music\n");

    while(!close){

        //Allows the user to write a command whenever he wants
        scanf("%c", &input);
        getchar();

        //Play/Pause a music
        if(input == 'p' || input == 'P'){

            //Play a music
            if (Mix_PlayingMusic() == 0){
                Mix_PlayMusic(music, 0);
         
            }else{
                //Pause/Unpause the music
                if (Mix_PausedMusic() == 0)
                    Mix_PauseMusic();
                else
                    Mix_ResumeMusic();
            }
			
			//Input variable needs to be reset
                input = '\0';
        }

        //Stop playing a music and/or change it
        if (input == 's' || input == 'S'){
            if (Mix_PlayingMusic()){
                Mix_HaltMusic(); //Stop playing a music
				
				//Reset variable and a vector
                input = '\0';
                nome[0] = '\0';
				
                //change music
                printf("Music stopped playing successful!\nIf you want to player another music, type the name below:\n");
                scanf("%s", name);
                getchar();
                music = Mix_LoadMUS(name);
                printf("Music loaded successful! type P to play it\n");
            }else{
				//Reset variable and a vector
                input = '\0';
                nome[0] = '\0';
				
                //Change music
                printf("Write the name of another music that you want:\n");
                scanf("%s", name);
                getchar();
                music = Mix_LoadMUS(name);
                printf("Music loaded successful! type P to play it\n");
            }
        }
    }
	
	//Shutdown SDL2 and SDL2_mixer
    close_program();

    return 0;
}
