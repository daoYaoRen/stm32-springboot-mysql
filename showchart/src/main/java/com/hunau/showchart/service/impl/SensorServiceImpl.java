package com.hunau.showchart.service.impl;

import com.hunau.showchart.entity.Sensor;
import com.hunau.showchart.mapper.SensorMapper;
import com.hunau.showchart.service.ISensorService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/***
 @author: 葛璐豪
 */
@Service
public class SensorServiceImpl implements ISensorService {
    @Autowired
    private SensorMapper sensorMapper;

    /**
     * @description 温湿度采集 查询
     *
     * @param
     * @return 温湿度采集 列表
     */
    @Override
    public List<Sensor> querrySensor()
    {
        return sensorMapper.querrySensor();
    }
    /**
     * @description 温湿度采集 存库
     *
     * @param
     * @return 温湿度采集 存库
     */
    @Override
    public int insertData(Sensor sensor){
        return sensorMapper.insertData(sensor);
    }
}
