#ifndef VITA2D_H
#define VITA2D_H

#include <psp2/gxm.h>
#include <psp2/types.h>
#include <psp2/kernel/memorymgr.h>

#define RGBA8(r,g,b,a) ((((a)&0xFF)<<24) | (((b)&0xFF)<<16) | (((g)&0xFF)<<8) | (((r)&0xFF)<<0))

typedef struct vita2d_clear_vertex {
	float x;
	float y;
} vita2d_clear_vertex;

typedef struct vita2d_color_vertex {
	float x;
	float y;
	float z;
	unsigned int color;
} vita2d_color_vertex;

typedef struct vita2d_texture_vertex {
	float x;
	float y;
	float z;
	float u;
	float v;
} vita2d_texture_vertex;

typedef struct vita2d_texture {
	SceGxmTexture gxm_tex;
	SceUID data_UID;
} vita2d_texture;


int vita2d_init();
int vita2d_fini();

void vita2d_clear_screen();
void vita2d_swap_buffers();

void vita2d_start_drawing();
void vita2d_end_drawing();

void *vita2d_pool_malloc(unsigned int size);
void *vita2d_pool_memalign(unsigned int size, unsigned int alignment);
unsigned int vita2d_pool_space_free();
void vita2d_pool_reset();

void vita2d_draw_rectangle(float x, float y, float w, float h, unsigned int color);

vita2d_texture *vita2d_create_empty_texture(unsigned int w, unsigned int h);
void vita2d_free_texture(vita2d_texture *texture);
unsigned int vita2d_texture_get_width(const vita2d_texture *texture);
unsigned int vita2d_texture_get_height(const vita2d_texture *texture);
void *vita2d_texture_get_datap(const vita2d_texture *texture);
void vita2d_draw_texture(const vita2d_texture *texture, float x, float y);
void vita2d_draw_texture_scale(const vita2d_texture *texture, float x, float y, float x_scale, float y_scale);


#endif