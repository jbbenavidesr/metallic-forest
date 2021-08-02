#ifndef ANIMATE_H
#define ANIMATE_H
/**
 * Defines useful functions for animationg with gnuplot.
 * @param animation: If 2, plot without saving. If 3, saves in a gif
 */
void start_animation(int animation);
void begin_frame(int animation);
void end_frame(int animation);
void plot_single_point(int animation, double x, double y);

#endif