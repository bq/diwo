use <publicDomainGearV1.1.scad>

ne = 11;
nc = 10;

mm_per_tooth = 9; //all meshing gears need the same mm_per_tooth (and the same pressure_angle)
thickness    = 8;
hole         = 3;
height       = 12;

d1 =pitch_radius(mm_per_tooth,n1);

module horn(H){
	union(){
		hull(){
			translate([0,-10,0])cylinder(r=2,h=H, $fn=20);
			translate([0,10,0])cylinder(r=2,h=H, $fn=20);
			translate([0,0,0])cylinder(r=3.2,h=H, $fn=20);
		}
		hull(){
			translate([-10,0,0])cylinder(r=2,h=H, $fn=20);
			translate([10,0,0])cylinder(r=2,h=H, $fn=20);
			translate([0,0,0])cylinder(r=3.2,h=H, $fn=20);
		}
		translate([0,0,-2])cylinder(r=3.3,h=H, $fn=20);
		translate([0,-10,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([0,10,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([-10,0,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([10,0,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([0,-6.5,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([0,6.5,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([-6.5,0,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([6.5,0,-10])cylinder(r=0.7,h=H+20, $fn=20);
		translate([0,0,-10])cylinder(r=1.5,h=H+20, $fn=20);
	}
		translate([0,0,0])cylinder(r=10,h=H, $fn=20);

}

module engranaje(){
	difference(){
		translate([0,0,0]) rotate([0,0, $t*360/n1]) gear(mm_per_tooth,ne,thickness,hole);
		translate([0,0,-2.3])horn(10);
	}
}

module cremallera(){
	difference(){
		union(){
			translate([(-floor(n5/2)-floor(n1/2)+$t+n1/2-1/2)*9, -d1+0.0, 0]) rack(mm_per_tooth,nc,thickness,height);
			translate([-20,-9.135,-4])cube([20,15,13]);
		}
		translate([-4,-1,2.5])rotate([0,-90,0])cylinder(r=5.5,h=40);
		%translate([-4,-1,2.5])rotate([0,-90,0])cylinder(r=5.5,h=40);
	}
}

module microservo(H){
	cylinder(r=2,h=30);
	translate([-12.5/2,-12.5/2,0])cube([12.5,24.5,H]);
	translate([0,-7.75,0]){
		cylinder(r=1.2,h=H,$fn=20);
		translate([0,27.5,0])cylinder(r=1.2,h=H,$fn=20);
	}
}

module bancada(H){
	difference(){
		union(){
			cube([24,35,90]);
			translate([4+15/2,4+17/2,0])rotate([0,0,45])hull(){
				translate([0,0,86])cylinder(r=18,h=4,$fn=20);
				translate([30,0,86])cylinder(r=5,h=4,$fn=20);
				translate([-30,0,86])cylinder(r=5,h=4,$fn=20);
			}
		}
		translate([4,4,-1])cube([9,60,60]);
		translate([-10,23,-1])cube([30,40,87]); //importante
		//translate([24,-1,-1])cube([30,40,95]); // 
		translate([4,4,42])cube([15,17,60]); 
		translate([4.5,4,42])rotate([0,45,0])cube([10,17,10]); 
		//translate([4.5,4,10])rotate([0,45,0])cube([10,17,10]); 
		translate([10,16,-1])cube([10,20,36]); 
		translate([8.5,30,20])rotate([90,0,90])microservo(50);
		translate([4+15/2,4+17/2,0])rotate([0,0,45]){
			//%translate([0,0,0])cylinder(r=1.8,h=100,$fn=20);
			translate([30,0,0])cylinder(r=1.8,h=100,$fn=20);
			translate([-30,0,0])cylinder(r=1.8,h=100,$fn=20);
		}
	}
}

module agujeros(){

		translate([5,30,0])cylinder(r=1.8,h=40,$fn=20);
		translate([39,8,0])cylinder(r=1.8,h=40,$fn=20);
		translate([8.5,13.5,0])rotate([0,90,0])translate([0,-1,3])rotate([0,-90,0])cylinder(r=6.5,h=40);
}






	bancada();
	/*translate([8.5,13.5,71])rotate([0,90,0])color("blue")cremallera();


