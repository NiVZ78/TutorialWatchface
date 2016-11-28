#include <pebble.h>

static Window *s_main_window;
static Layer *s_main_window_layer;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_image;


static void main_window_load(Window *window) {

  // Set the main window background color to black
  window_set_background_color(s_main_window, GColorBlack);
  
  // Create the main window layer
  s_main_window_layer = window_get_root_layer(s_main_window);
  
  // Add the background layer
  s_background_layer = bitmap_layer_create(layer_get_bounds(s_main_window_layer));
  
  // Add the background layer to the main window layer
  layer_add_child(s_main_window_layer, bitmap_layer_get_layer(s_background_layer));
  
  // Create the background image
  s_background_image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  
  // Set the background image onto the background layer
  bitmap_layer_set_bitmap(s_background_layer, s_background_image);
  
  
  
}

static void main_window_unload(Window *window) {

}

static void init() {

  // Create the main Window 
  s_main_window = window_create();

  // Set the main Window load and unload handlers
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch
  window_stack_push(s_main_window, true);

}

static void deinit() {

  // Destroy Window
  window_destroy(s_main_window);

}

int main(void) {
    init();
    app_event_loop();
    deinit();
}