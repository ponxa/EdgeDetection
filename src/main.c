#include <stdio.h>
#include <stdlib.h>

#include "argparser.h"
#include "convolution.h"
#include "derivation.h"
#include "gaussian_kernel.h"
#include "image.h"

int main(int const argc, char **const argv) {
    /**
     * Parse arguments. The parsed image file name and threshold are available
     * in the image_file_name and threshold global variables (see argparser.h).
     */
    parse_arguments(argc, argv);
    printf("Computing edges for image file %s with threshold %i\n",
           image_file_name, threshold);

    /**
     * Read Image from given file.
     *
     * If the input file is broken terminate with return value 1.
     *
     * Hint: The width and height of the image have to be accessible in the
     * scope of this function.
     */
    // TODO: Implement me!
    
    int width=0;
    int height=0;
    int *w = &width;
    int *h = &height;
    
    float *img=read_image_from_file(image_file_name, w, h);
    if(img == NULL){
           return 1;
    }


    /**
     * Blur the image by using convolve with the given Gaussian kernel matrix
     * gaussian_k (defined in gaussian_kernel.h). The width of the matrix is
     * gaussian_w, the height is gaussian_h.
     *
     * Afterwards, rescale the resulting blurred image and write the rescaled
     * result to the file out_blur.pgm.
     */
    // TODO: Implement me!
   
     float *resultblur=malloc(sizeof(float)*(*w * *h));
     convolve(resultblur, img, *w, *h, gaussian_k, gaussian_w,gaussian_h);
     write_image_to_file(resultblur, *w,  *h, " out_blur.pgm");


    /**
     * Compute the derivation of the (unscaled!) blurred image computed above
     * in both x and y direction.
     *
     * Afterwards, rescale both results and write them to the files out_d_x.pgm
     * and out_d_y.pgm respectively.
     */
    // TODO: Implement me!
    float *resultblurDevX = malloc(sizeof(float)*(*w* *h));
    float *resultblurDevY = malloc(sizeof(float)*(*w* *h));
     float *resultblurScaledDevX = malloc(sizeof(float)*(*w* *h));
    float *resultblurScaledDevY = malloc(sizeof(float)*(*w* *h));
    derivation_x_direction(resultblurDevX, resultblur, *w, *h);
    derivation_y_direction(resultblurDevY, resultblur, *w, *h);
    scale_image(resultblurScaledDevX, resultblurDevX, *w,  *h);
    scale_image(resultblurScaledDevY,resultblurDevY , *w,  *h);
    write_image_to_file(resultblurScaledDevX, *w,  *h, " out_d_x.pgm");
    write_image_to_file(resultblurScaledDevY, *w,  *h, " out_d_x.pgm");
    /**
     * Compute the gradient magnitude of the blurred image by using the
     * (unscaled!) derivations in x- and y-direction computed earlier.
     *
     * Afterwards, rescale the result and write it to out_gm.pgm.
     */
    // TODO: Implement me!
     float *gradImg = malloc(sizeof(float)*(*w* *h));
     float *gradImgScaled = malloc(sizeof(float)*(*w* *h));
     gradient_magnitude(gradImg,resultblurDevX, resultblurDevY, *w, *h);
     scale_image(gradImgScaled, gradImg, *w,*h);
     write_image_to_file(gradImgScaled, *w, *h, "out_gm.pgm ");
    /**
     * Apply the threshold to the gradient magnitude.
     * Then write the result to the file out_edges.pgm.
     */
    // TODO: Implement me!
    float *threshImg = malloc(sizeof(float)*(*w* *h));
    float *ScaledthreshImg = malloc(sizeof(float)*(*w* *h));
    apply_threshold(threshImg, *w,  *h, threshold);
    scale_image(ScaledthreshImg, threshImg, *w, *h);
    write_image_to_file(ScaledthreshImg, *w, *h, "out_edges.pgm ");

    /**
     * Remember to free dynamically allocated memory when it is no longer used!
     */
     free(resultblur);
     free(resultblurDevX);
     free(resultblurDevY);
     free(resultblurScaledDevX);
     free(resultblurScaledDevY);
     free(gradImg);
     free(gradImgScaled);
     free(threshImg);
     return 0;

}
