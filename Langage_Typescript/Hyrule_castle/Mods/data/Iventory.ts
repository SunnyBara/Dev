export class Inventory{
    monei : number;
    items : Item[];
    constructor (){
        this.monei = 12;
        this.items = [];
    };
    set_monei(change : number){
        this.monei += change;
    }

}

export class Item {
    name : string;
    Description : string;
}


