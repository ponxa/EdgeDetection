#include "convolution.h"

#include <stdlib.h>

#include "image.h"

void convolve(float *result, const float *img, int w, int h,
              const float *matrix, int w_m, int h_m) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;
    (void)matrix;
    (void)w_m;
    (void)h_m;

    // TODO: Implement me!
    int pixelPosValue = 0;
    
    //width values img
    for(int i =0 ; i <= w-1; i++){

        //height values img
        
        for(int j =0 ; j <= h-1; j++){
            
            pixelPosValue = i+j*w;
            result[pixelPosValue]=0;
            
            //kernel width values
            for(int k =0 ; k <= w_m-1; k++){
                //kernel height values
                for(int l =0 ; l <= h_m-1; l++){
                result[pixelPosValue]+= matrix[k+l*(w_m)]*get_pixel_value(img, w, h, k+i-((w_m-1)/2)  ,l+j-((h_m-1)/2));
                
                }
              
            }
        }

    }
}
