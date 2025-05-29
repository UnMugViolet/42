#include "mlx.h"
int main() {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 100, 100, "test");
    int w, h;
    void *img = mlx_xpm_file_to_image(mlx, "./grass.xpm", &w, &h);
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}