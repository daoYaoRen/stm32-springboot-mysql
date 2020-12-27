package com.hunau.showchart.mapper;

import com.hunau.showchart.entity.Sensor;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

import java.util.List;

/***
 @author: 葛璐豪
 */
@Repository
public interface SensorMapper {
    @Select("SELECT * FROM sensor_data")
    public List<Sensor> querrySensor();

    @Insert({ "insert into " +
            "sensor_data(id, people,led,beep,time) " +
            "values(#{id},#{people},#{led},#{beep},#{time})" })
    public int insertData(Sensor sensor);
}
