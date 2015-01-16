//Opciones de pivotes

module A(){
	difference(){
		union(){
			cylinder(r=13/2,h=30);
			translate([0,0,30])sphere(13/2);
		}
		translate([0,0,-1])cylinder(r=11/2,h=31);
	}
}

module B(){
	difference(){
		union(){
			cylinder(r1=20/2,r2=13/2,h=30);
			translate([0,0,30])sphere(13/2);
		}
		translate([0,0,-1])cylinder(r=11/2,h=31);
	}
}

module C(){
	difference(){
		union(){
			cylinder(r=13/2,h=20);
			translate([0,0,18])sphere(16/2);
		}
		translate([0,0,-1])cylinder(r=11/2,h=23);
		//translate([0,0,15])cube(20);
	}
}

module D(ajuste){
	difference(){
		union(){
			cylinder(r=13/2,h=30);
			translate([0,0,30])cylinder(r1=13/2,r2=4,h=2);
		}
		translate([0,0,-1])cylinder(r=11/2,h=30);
		//translate([0,0,15])cube(20);
		translate([0,0,29.5+ajuste])sphere(ajuste);

	}
}

module E(ajuste){
	difference(){
		union(){
			cylinder(r1=16,r2=7,h=16,$fn=6);


		}
		translate([0,0,-1])cylinder(r=12/2,h=16);
		//translate([0,0,10])cube(20);

	}
}

module F(ajuste){
	difference(){
		hull(){
			cylinder(r=20,h=1,$fn=50);
			translate([0,0,6-ajuste])sphere(20,$fn=100);


		}
		translate([0,0,-1])cylinder(r=12/2,h=25-ajuste);
		//translate([0,0,10])cube(20);
		translate([0,0,-50])cube(100, center=true);
		translate([0,0,74.8-ajuste])cube(100, center=true);

	}
}

module G(ajuste){
	difference(){
		hull(){
			cylinder(r=17,h=1,$fn=50);
			translate([0,0,10])sphere(10,$fn=50);


		}
		translate([0,0,-1])cylinder(r=12/2,h=24-ajuste);
		//translate([0,0,10])cube(20);
		translate([0,0,-50])cube(100, center=true);
		translate([0,0,74-ajuste])cube(100, center=true);

	}
}

module H(ajuste){
	difference(){
		hull(){
			cylinder(r=17,h=1,$fn=50);
			translate([0,0,10])sphere(10,$fn=50);


		}
		translate([0,0,-1])cylinder(r=12/2,h=24-ajuste);
		//translate([0,0,10])cube(20);
		translate([0,0,-50])cube(100, center=true);
		translate([0,0,74-ajuste])cube(100, center=true);

	}
}

module base(){
	difference(){
		translate([-30,-30,0])cube([60,60,10]);
		translate([-28,-28,2])cube([56,56,15]);
		translate([0,0,-1])cylinder(r=12/2,h=23);		
	}
}

module agujeros(){

		translate([5,30,0])cylinder(r=1.8,h=40,$fn=20);
		translate([39,8,0])cylinder(r=1.8,h=40,$fn=20);
		translate([8.5,13.5,0])rotate([0,90,0])translate([0,-1,3])rotate([0,-90,0])cylinder(r=6.5,h=40);
}

difference(){
	union(){
		translate([0,0,10])H(6);
		cylinder(r=17,h=11,$fn=60);
		hull(){
			cylinder(r=20,h=2,$fn=60);
			translate([30,0,0])cylinder(r=5,h=2,$fn=20);
			translate([-30,0,0])cylinder(r=5,h=2,$fn=20);
		}
	}
	translate([30,0,-1])cylinder(r=1.8,h=4,$fn=20);
	translate([-30,0,-1])cylinder(r=1.8,h=4,$fn=20);
	rotate([0,0,-45])cube([15,17,23],center=true);
}