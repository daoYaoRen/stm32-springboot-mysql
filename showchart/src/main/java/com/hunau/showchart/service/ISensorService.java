package com.hunau.showchart.service;

import com.hunau.showchart.entity.Sensor;

import java.util.List;

/***
 @author: 葛璐豪
 */

public interface ISensorService {
    public List<Sensor> querrySensor();

    public int insertData(Sensor sensor);
}
