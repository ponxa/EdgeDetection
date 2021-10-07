#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apply_threshold(float *img, int w, int h, int T) {
    (void)img;
    (void)w;
    (void)h;
    (void)T;

    // TODO: Implement me!
    //values bigger than T go to white(255) and values smaller than T go black(0)
    for(int i=0;i < w*h ;i++){
        if(img[i]>=T){
            img[i]=255;
        }else if(img[i]<T){
            img[i]=0;
        }
    }return;
}

void scale_image(float *result, const float *img, int w, int h) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;

    // TODO: Implement me!
    //first step is find the min and max values of the array 
    int imgMin,imgMax;
    imgMin = imgMax = img[0];
    int pixelPosValue;
    for(int i = 0;i < w*h;i++){
        if(img[i] >= imgMax){
            imgMax = img[i];
        }
    }  
    for(int j = 0;j < w*h;j++){
        if(img[j] <= imgMin){
            imgMin = img[j];
        }
    }
    //if Max and Min values of the image are equal then return 
    if(imgMax==imgMin){
    for(int k =0 ; k < w*h;k++){
        result[k]=0;
    }    
    //applying the scaling of gray values    
    }else{
        for(int i =0 ;i < w ; i++){
            for(int j=0 ; j < h ;j++){
                pixelPosValue= i + j*w;
                result[pixelPosValue]=((img[pixelPosValue]-imgMin)/(imgMax-imgMin))*255;
            }


        }
    }
    

}

float get_pixel_value(const float *img, int w, int h, int x, int y) {
    (void)img;
    (void)w;
    (void)h;
    (void)x;
    (void)y;

    // TODO: Implement me!
    //from description of the proyect the mirroring of the x,y value should be for ex:B(mp(-1,-1))=B(0,0)
    int pixelPosValue=0;
    if(x==0 || x < w ){
        x = x;
    }
    if(x<0){
        x= -x-1;
        }
    if(x >= w){
        x=2*w-x-1;
    }
    if(y ==0 || y < h ){
        y= y;
    }
    if(y < 0 ){
        y= -y - 1;
       
    }
    if(y >= h){
        y=2*h-y-1;
        
    }
    pixelPosValue = x+ y*w;

    return img[pixelPosValue];
}

float *array_init(int size) {
    (void)size;

    // TODO: Implement me!
    float *arrayInit = malloc(size*sizeof(float));
    for(int i =0 ; i< size ;i++){
        arrayInit[i]=-1;
    }

    return arrayInit; 
    //return NULL;
}

void array_destroy(float *m) {
    (void)m;

    // TODO: Implement me!
    free(m);
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    (void)filename;
    (void)w;
    (void)h;

    // TODO: Implement me!
    char chr1;
    char chr2;
    int hellMax;
    float *arrayInit;
    int inputVal;
    FILE *f=fopen(filename,"r");
    if(f== NULL){
        
        fclose(f);
        return NULL;
    }
    fscanf(f,"%c%c%d%d%d",&chr1,&chr2,w,h,&hellMax);
    if(chr1 != 'P'|| chr2 != '2'){
        
        fclose(f);
        return NULL;

    }
    if(*h <0 || *w < 0){
        
        fclose(f);
        return NULL;
    }
    arrayInit = array_init((*h)*(*w));
    int counter=0;
    for(int i = 0;i <= (*h)*(*w)-1;i++){
        
        fscanf(f,"%d",&inputVal);
        counter+=1;
        arrayInit[i]=inputVal;
        
    }
 
    

    return arrayInit;


    
    

    //return NULL;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    (void)img;
    (void)w;
    (void)h;
    (void)filename;

    // TODO: Implement me!
    
    FILE *f = fopen(filename,"w");
    
    int c = 0;
    int ch =0;
    char newline[2] = "\n";
    fprintf(f,"P2\n%d %d\n%d\n",w,h,255);
    for (int i =0;i<= w*h-1;i++){
        
    fprintf(f,"%d",(int)roundf(img[i]));
    c++;
    if(c == w-1){
     fprintf(f,"%c",*newline);
     c =0;
     ch++;  
    }
    

    }

    fclose(f);
    return;

}
