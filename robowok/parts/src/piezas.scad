module m3(H) cylinder(r=1.75,h=H,$fn=30,center=true);


module pvc(H){
	color("grey")cylinder(h=H,r=20.5,center=true);
}

module horn(){


}

module taladros(H){
	translate([16,16,-10])m3(30);
	translate([16,-16,-10])m3(30);
	translate([-16,16,-10])m3(30);
	translate([-16,-16,-10])m3(30);
	translate([16,16,H])cylinder(r=3.2, h=8, $fn=20);
	translate([-16,16,H])cylinder(r=3.2, h=8, $fn=20);
	translate([16,-16,H])cylinder(r=3.2, h=8, $fn=20);
	translate([-16,-16,H])cylinder(r=3.2, h=8, $fn=20);
}

module servo_996r(H){
	cube([41.5,21,H],center=true);
	translate([25,5,0])m3(H);
	translate([-25,-5,0])m3(H);
	translate([25,-5,0])m3(H);
	translate([-25,5,0])m3(H);
}

module soporte_barra(){
	difference(){
		hull(){
			translate([-28,-28,0])cube([56,56,40]);
		}
		hull(){
			translate([0,0,30])rotate([0,90,0])pvc(100);
			translate([0,0,50])rotate([0,90,0])pvc(100);
		}
		translate([15,0,30])rotate([90,0,0])cylinder(h=100,r=2.25,$fn=20,center=true);
		translate([-15,0,30])rotate([90,0,0])cylinder(h=100,r=2.25,$fn=20,center=true);
		taladros(3);
	}
}

module soporte_servo(){
	difference(){
		union(){
			translate([-28,-28,0])cube([56,56,4]);
			translate([-28,0,0])cube([56,8,30]);
		}

		translate([0,0,16])rotate([90,0,0])servo_996r(100);
		taladros(2);
	}
}

module anilla(){
	difference(){
		union(){
			cylinder(r=76/2+4,h=30,$fn=100);
			translate([5,-20,0])cube([50,40,30]);
			translate([50,-35,0])cube([5,70,30]);
		}
		translate([0,0,-1])cylinder(r=75.5/2,h=32,$fn=100);
		translate([55,28,15])rotate([0,90,0])m3(20);
		translate([55,-28,15])rotate([0,90,0])m3(20);
		rotate([0,0,-40])translate([0,0,-1])cube([1.5,100,100]);
	}

}

module soporte_bote(){
	difference(){
		union(){
			translate([-90,-35,0])cube([180,70,3]);
			translate([10,30,0])cube([20,15,20]);
			translate([-30,30,0])cube([20,15,20]);
			translate([-10,-23,0])cube([70,10,23]);			
		}
		translate([75,-28,-1])m3(20);
		translate([75,28,-1])m3(20);
		translate([-75,-28,-1])m3(20);
		translate([-75,28,-1])m3(20);

		//%translate([65,-20,-1])m3(20);
		//%translate([65,20,-1])m3(20);
		//%translate([-65,-20,-1])m3(20);
		//%translate([-65,20,-1])m3(20);
		
		translate([0,37.5,12.5])rotate([0,90,0])m3(100);
		translate([20,-15,14])rotate([90,0,0])servo_996r(30);
		taladros(2);
		rotate([0,0,-30])taladros(2);
		rotate([0,0,-15])taladros(2);
		rotate([0,0,45])taladros(2);

		
	}
}

ang=0;
module gatillo(){
	difference(){
		union(){
			cylinder(r=6,h=20);
			rotate([0,0,-20])translate([-2,0,0])cube([4,80,20]);
			translate([10,80,0])cylinder(r=76/2+4,h=20);
			hull(){
				translate([0,90,0])rotate([0,0,ang])translate([110,0,0])cylinder(r=2,h=20,$fn=20);
				translate([0,90,0])cylinder(r=2,h=20,$fn=20);
			}

		}

		translate([0,90,0])rotate([0,0,ang])translate([100,10,10])rotate([90,0,0])cylinder(r=2,h=20,$fn=20);
		translate([10,80,-1])cylinder(r=75.5/2,h=22);
		translate([-102.1,20,-1])cube([100,200,50]);
		translate([-102.1,20,-1])cube([100,200,50]);
		translate([-10,92.1,-1])cube([100,100,50]);
		translate([-44.5,30,-10])rotate([0,0,-20])cube([50,80,40]);
		m3(50);
		
	}

}

module catapulta(){
	difference(){
		union(){
			translate([0,10,0])cylinder(r=10,h=5);
			cube([100,20,5]);
			translate([60,0,0])cube([40,6,40]);

			hull(){
				translate([77,0,0])cube([6,6,40]);
				translate([77,0,0])cube([6,20,5]);
			}
		}
		translate([65,20,10])rotate([90,0,0])cylinder(r=1.75,h=50,$fn=20);
		translate([95,20,10])rotate([90,0,0])cylinder(r=1.75,h=50,$fn=20);
		translate([65,20,35])rotate([90,0,0])cylinder(r=1.75,h=50,$fn=20);
		translate([95,20,35])rotate([90,0,0])cylinder(r=1.75,h=50,$fn=20);

		hull(){
			translate([0,10,-7])cylinder(r=7,h=10);
			translate([41-7-4.5,10,-7])cylinder(r=4.5,h=10);

		}
		translate([0,10,-4])cylinder(r=5,h=50);
		translate([16,10,-4])cylinder(r=1.75,h=50,$fn=20);
		translate([30,10,-4])cylinder(r=1.75,h=50,$fn=20);

	}
}

module soporte_soplador(){
	difference(){
		union(){
			translate([0,0,30])rotate([0,90,0])cylinder(r=39/2+3,h=56,center=true);
			translate([-28,-28,0])cube([56,56,4]);
			translate([-28,-10,0])cube([56,20,40]);
		}
		translate([0,0,30])rotate([0,90,0])cylinder(r=39/2,h=60,center=true);
			translate([0,0,80])cube([100,5,80],center=true);
		taladros(2);


	}

}

module punta_soplador(){
	difference(){
		union(){
			translate([0,0,30])rotate([0,90,0])cylinder(r=39/2+3,h=30,center=true);
			translate([-15,-15,0])cube([70,30,4]);
			translate([-15,-10,0])cube([30,20,40]);
		}
		translate([0,0,30])rotate([0,90,0])cylinder(r=39/2,h=60,center=true);
		translate([0,0,80])cube([100,5,80],center=true);


	}

}

punta_soplador();

//translate([10,37.5,12.5])rotate([60,0,0])rotate([0,-90,0])gatillo();
/*translate([60,0,68])rotate([0,90,0])/**///anilla();
/*translate([-90,0,68])rotate([0,90,0])anilla();
soporte_bote();
/**/


