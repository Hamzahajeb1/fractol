#include "fractol.h"

static void    data(t_fractal *fract)
{
    fract->esc = 4;
    fract->iteration = 42;
    fract->x_shift = 0.0;
    fract->y_shift = 0.0;
    fract->zoom = 1.0;

}

static void event(t_fractal *fract)
{
    mlx_hook(fract->mlx_window, KeyPress, KeyPressMask, handle_Key, fract);
   mlx_hook(fract->mlx_window, ButtonPress, ButtonPressMask, handle_mouse, fract);
   mlx_hook(fract->mlx_window, DestroyNotify, StructureNotifyMask, handle_close, fract);
    mlx_hook(fract->mlx_window, MotionNotify, PointerMotionMask, julia_track, fract);

}

void ft_init(t_fractal *fract)
{
    fract->mlx = mlx_init();
    if (!fract->mlx)
    {
        write (1,"connection error!", 17);
        exit (1);
    }
    fract->mlx_window = mlx_new_window(fract->mlx, WIDTH , HEIGHT, fract->name);
    if (!fract->mlx_window)
    {
        mlx_destroy_display(fract->mlx);
        free(fract);
        write (1, "window error!", 13);
        exit(1);
    }
    fract->image.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    if (!fract->image.img)
    {
        mlx_clear_window(fract->mlx, fract->mlx_window);
        mlx_destroy_display(fract->mlx);
        write (1, "image error!", 12);
        free(fract->mlx);
    }
    fract->image.pixl = mlx_get_data_addr(fract->image.img, &fract->image.bit_pix, &fract->image.size_line, &fract->image.endian);
    event(fract);
    data(fract);
}