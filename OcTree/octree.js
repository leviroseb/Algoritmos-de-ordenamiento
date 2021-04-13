var alpha = 0.2;

class Point{
    constructor(x,y,z){
        this.x = x;
        this.y = y;
        this.z = z;
        this.geometry = new THREE.SphereGeometry( 4, 12, 12 );
        this.material = new THREE.MeshBasicMaterial();
        this.sphere = new THREE.Mesh( this.geometry, this.material );
        this.sphere.position.set(x,y,z);
        scene.add( this.sphere );
    }
}

class Box
{
    constructor(x,y,z,w,h,d)
    {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
        this.h = h;
        this.d = d;
    }

    contains(point){
        return (point.x >= (this.x - this.w) && 
        point.x <= (this.x + this.w) && 
        point.y >= (this.y - this.h) && 
        point.y <= (this.y + this.h) &&
        point.z >= (this.z - this.d) &&
        point.z <= (this.z + this.d)); 
    }

    intersects(box){
        return !(box.x - box.w > this.x + this.w  ||
        box.x + box.w < this.x - this.w  ||
        box.y - box.h > this.y + this.h  ||
        box.y + box.h < this.y - this.h  ||
        box.z - box.d > this.z + this.d  ||
        box.z + box.d < this.z - this.d);
    }
}

class Octree{
    constructor(box,n){
        this.box = box;
        this.capacity = n;
        this.points = [];
        this.divided = false;

        this.color = new THREE.Color( Math.random()*1,Math.random()*1,Math.random()*1);

        this.geometry = new THREE.BoxGeometry(box.w*2,box.h*2,box.d*2);
        this.material = new THREE.MeshBasicMaterial( { color: 0x00ff00, opacity: alpha, transparent: true, } );
        this.material.color.set(this.color);
        this.cube = new THREE.Mesh( this.geometry, this.material );
        this.cube.position.set(box.x,box.y,box.z);
        scene.add(this.cube);
    }

    subdivide(){
        let x = this.box.x;
        let y = this.box.y;
        let z = this.box.z;
        let w = this.box.w/2;
        let h = this.box.h/2;
        let d = this.box.d/2;

        let NorthWestF = new Box(x-w,y-h,z-d,w,h,d); 
        let NorthEastF = new Box(x+w,y-h,z-d,w,h,d);
        let SouthWestF = new Box(x-w,y+h,z-d,w,h,d);
        let SouthEastF = new Box(x+w,y+h,z-d,w,h,d);
        let NorthWestB = new Box(x-w,y-h,z+d,w,h,d);
        let NorthEastB = new Box(x+w,y-h,z+d,w,h,d);
        let SouthWestB = new Box(x-w,y+h,z+d,w,h,d);
        let SouthEastB = new Box(x+w,y+h,z+d,w,h,d);

        this.sonNWF = new Octree(NorthWestF,this.capacity);
        this.sonNEF = new Octree(NorthEastF,this.capacity);
        this.sonSWF = new Octree(SouthWestF,this.capacity);
        this.sonSEF = new Octree(SouthEastF,this.capacity);
        this.sonNWB = new Octree(NorthWestB,this.capacity);
        this.sonNEB = new Octree(NorthEastB,this.capacity);
        this.sonSWB = new Octree(SouthWestB,this.capacity);
        this.sonSEB = new Octree(SouthEastB,this.capacity);

        alpha = alpha + 0.1;
        this.divided = true;
    }

    insert(point){
        if(!this.box.contains(point)){
            return false;
        }
        if(this.points.length<this.capacity){
            this.points.push(point);
            point.material.color.set(this.color);
            return true;
        }
        if(!this.divided){
            this.subdivide();
        }
        return (this.sonNWF.insert(point) ||
            this.sonNEF.insert(point) ||
            this.sonSWF.insert(point) ||
            this.sonSEF.insert(point) ||
            this.sonNWB.insert(point) ||
            this.sonNEB.insert(point) ||
            this.sonSWB.insert(point) ||
            this.sonSEB.insert(point) );
    }

    query(box,found){
        if(!this.box.intersects(box)){
            return;
        }
        else{
            for(let p of this.points){
                if(box.contains(p)){
                    p.material.color.set(new THREE.Color(1,1,1));
                    found.push(p);
                }
            }
            if(this.divided){
                this.sonNWF.query(box,found);
                this.sonNEF.query(box,found);
                this.sonSWF.query(box,found);
                this.sonSEF.query(box,found);
                this.sonNWB.query(box,found);
                this.sonNEB.query(box,found);
                this.sonSWB.query(box,found);
                this.sonSEB.query(box,found);
            }
        }
    }

    cleanQuery(box){
        if(!this.box.intersects(box)){
            return;
        }
        else{
            for(let p of this.points){
                if(box.contains(p)){
                    p.material.color.set(this.color);
                }
            }
            if(this.divided){
                this.sonNWF.cleanQuery(box);
                this.sonNEF.cleanQuery(box);
                this.sonSWF.cleanQuery(box);
                this.sonSEF.cleanQuery(box);
                this.sonNWB.cleanQuery(box);
                this.sonNEB.cleanQuery(box);
                this.sonSWB.cleanQuery(box);
                this.sonSEB.cleanQuery(box);
            }
        }
    }
}