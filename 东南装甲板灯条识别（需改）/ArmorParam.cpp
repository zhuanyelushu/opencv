#include "ArmorParam.h"

ArmorParam::ArmorParam()
{
    /*
    *	@Brief: 为各项参数赋默认值
    */
    //pre-treatment
    brightness_threshold = 210;
    color_threshold = 40;
    light_color_detect_extend_ratio = 1.1;

    // 过滤灯条
    light_min_area = 100;//原来是10
    light_max_angle = 45.0;
    light_min_size = 5.0;
    light_contour_min_solidity = 0.5;
    light_max_ratio = 0.4;//原来是1

    // Filter pairs
    light_max_angle_diff_ = 7.0; //20
    light_max_height_diff_ratio_ = 0.2; //0.5
    light_max_y_diff_ratio_ = 2.0; //100
    light_min_x_diff_ratio_ = 0.5; //100

    // Filter armor
    armor_big_armor_ratio = 3.2;
    armor_small_armor_ratio = 2;
    //armor_max_height_ = 100.0;
    //armor_max_angle_ = 30.0;
    armor_min_aspect_ratio_ = 1.0;
    armor_max_aspect_ratio_ = 5.0;

    //other params
    sight_offset_normalized_base = 200;
    area_normalized_base = 1000;
    enemy_color = BLUE;

}

