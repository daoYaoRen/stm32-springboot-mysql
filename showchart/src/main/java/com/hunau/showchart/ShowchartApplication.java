/*
 * @Description: 
 * @Version: 2.0
 * @Autor: 葛璐豪
 * @Date: 2020-12-25 21:54:30
 * @LastEditors: Seven
 * @LastEditTime: 2020-12-26 16:40:41
 */
package com.hunau.showchart;

import com.hunau.showchart.bluetooth.BluetoothService;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.hunau.showchart.mapper")
public class ShowchartApplication {
    public static void main(String[] args) {
        SpringApplication.run(ShowchartApplication.class, args);
        BluetoothService bluetoothService = new BluetoothService();
        bluetoothService.start();

    }

}
