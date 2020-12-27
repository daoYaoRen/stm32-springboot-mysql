/*
 * @Description: 
 * @Version: 2.0
 * @Autor: 葛璐豪
 * @Date: 2020-11-21 11:25:05
 * @LastEditors: Seven
 * @LastEditTime: 2020-12-26 16:40:04
 */
package com.hunau.showchart.controller;

import com.hunau.showchart.entity.Sensor;
import com.hunau.showchart.mapper.SensorMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

@Controller
public class RoutreController {
    @Autowired
    private SensorMapper sensorMapper;
    @GetMapping("")
    private  String index() {
        return "index";
    }

    @GetMapping("/chart")
    private  String chart() {
        return "chart";
    }


    @GetMapping("/baseData")
    @ResponseBody
    public List<Sensor> baseData(ModelMap modelMap)
    {
        return sensorMapper.querrySensor();
    }
}
