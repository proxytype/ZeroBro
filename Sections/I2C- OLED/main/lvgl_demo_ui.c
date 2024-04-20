/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "lvgl.h"

void example_lvgl_demo_ui(lv_disp_t *disp)
{
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    lv_obj_t *label = lv_label_create(scr);
    
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR); /* Circular scroll */
    lv_obj_set_style_text_font(label, &lv_font_montserrat_20, 0);
    lv_label_set_text(label, "        ZeroBRO        ");

    int *size;
    size = 28;
    //lv_obj_set_style_text_color(label, lv_color_white(), LV_PART_MAIN);
    //lv_obj_set_style_text_font(label, size, 0);
    lv_obj_set_width(label, 100);

    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}
