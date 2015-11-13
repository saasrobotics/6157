
package com.qualcomm.ftcrobotcontroller.opmodes;

import com.qualcomm.robotcore.eventloop.opmode.OpMode;
import com.qualcomm.robotcore.util.ElapsedTime;

import java.text.SimpleDateFormat;
import java.util.Date;

import android.app.Activity;

import com.qualcomm.robotcore.eventloop.opmode.OpMode;
import com.qualcomm.robotcore.hardware.DcMotor;
import com.qualcomm.robotcore.hardware.DcMotorController;
import com.qualcomm.robotcore.hardware.DeviceInterfaceModule;
import com.qualcomm.robotcore.hardware.Servo;
import com.qualcomm.robotcore.hardware.ServoController;
import com.qualcomm.robotcore.hardware.TouchSensor;
import com.qualcomm.robotcore.util.Range;

/**
 * TeleOp Mode
 * <p>
 *Enables control of the robot via the gamepad
 */
public class adamsopmode extends OpMode {


	//constructor
	public adamsopmode() {


	}

	private String startDate;
	private ElapsedTime runtime = new ElapsedTime();

	//Controllers
	private DcMotorController mydcmotorcontroller;

	private ServoController Robot_servo_Controller;
	private DcMotorController myarmcontroller;
	//Motors
	private DcMotor my_dcmotor_left;
	private DcMotor my_dcmotor_right;
	private DcMotor dcmotor_arm;

	//Servos
	//private Servo arm_servo;
	private Servo robot_front_left;
	private Servo robot_front_right;
	private Servo front_arm_rotation;

	public void setDrivePower(double leftpower, double rightpower){
		this.my_dcmotor_left.setPower(leftpower);
		this.my_dcmotor_right.setPower(rightpower);
	}

	public void setArmLiftPower (double power){

		this.dcmotor_arm.setPower(power);
	}

	public void setServoPosition(double frontleftpos, double frontrightpos, double armrotationpos){
		this.robot_front_left.setPosition(frontleftpos);
		this.robot_front_right.setPosition(frontrightpos);
		this.front_arm_rotation.setPosition(armrotationpos);
	}

	/*
     * Code to run when the op mode is first enabled goes here
     * @see com.qualcomm.robotcore.eventloop.opmode.OpMode#start()
     */
	@Override
	public void init() {
		startDate = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss").format(new Date());
		runtime.reset();

		mydcmotorcontroller = hardwareMap.dcMotorController.get("drive_controller");
		myarmcontroller = hardwareMap.dcMotorController.get("arm_controller");
		Robot_servo_Controller = hardwareMap.servoController.get("servo_controller");
		dcmotor_arm = hardwareMap.dcMotor.get("arm_motor");
		my_dcmotor_left = hardwareMap.dcMotor.get("left_drive");
		my_dcmotor_right = hardwareMap.dcMotor.get("right_drive");
		robot_front_left = hardwareMap.servo.get("frontleftservo");
		robot_front_right = hardwareMap.servo.get("frontrightservo");
       front_arm_rotation = hardwareMap.servo.get("frontarmservo");



	}

	/*
     * This method will be called repeatedly in a loop
     * @see com.qualcomm.robotcore.eventloop.opmode.OpMode#loop()
     */
	@Override
	public void loop() {


	}
}
