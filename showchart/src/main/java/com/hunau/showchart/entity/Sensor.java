/*
 * @Description: 
 * @Version: 2.0
 * @Autor: 葛璐豪
 * @Date: 2020-12-26 16:16:03
 * @LastEditors: Seven
 * @LastEditTime: 2020-12-26 16:39:54
 */
package com.hunau.showchart.entity;
public class Sensor {
    /**数据编号*/
    private int id;
    /**是否有人*/
    private String people;
    private String led;

    public String getLed() {
        return led;
    }

    public void setLed(String led) {
        this.led = led;
    }

    public String getBeep() {
        return beep;
    }

    public void setBeep(String beep) {
        this.beep = beep;
    }

    private String beep;
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPeople() {
        return people;
    }

    public void setPeople(String people) {
        this.people = people;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    @Override
    public String toString() {
        return "Sensor{" +
                "id=" + id +
                ", people='" + people + '\'' +
                ", led='" + led + '\'' +
                ", beep='" + beep + '\'' +
                ", time='" + time + '\'' +
                '}';
    }

    /**采集时间*/
    private String time;


}
