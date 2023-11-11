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
    add(item : Item){
        if(this.exist(item)) {
          const my_item = this.find_item(item.name)
          if(my_item !== null)
            my_item.count += 1;
        } else {
            this.items.push(item);

        }
    }
    Use(item:Item) {
        const my_item  = this.find_item(item.name);
        if(my_item !== null) {
            my_item.count -= 1;
            if(my_item.count === 0){
                this.items.splice(this.items.indexOf(my_item),1);
            }    
        }
    }

    exist(item : Item) {
        for (const items of this.items) {
            if(item.name === items.name) {
                return(true);
            }
        }
        return(false)
    }

    find_item(item_name: string) {
        for (const items of this.items) {
            if(item_name === items.name) {
                return(items);
            }
        }
        return(null)
    }

}

export class Item {
    name : string;
    Description : string;
    count : number;
}


