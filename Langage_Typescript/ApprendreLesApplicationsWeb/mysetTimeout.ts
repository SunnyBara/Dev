function display(x) {
    console.log(x);
}
async function main() {
    let x = 0;
display(x);
x = 132;
setTimeout(display,1500,x);
x = 15;
setTimeout(display,1000,x);
x = 12; 
setTimeout(display,1250,x);

}
main();


async function mysetTimeout(callback:Function, duration : number,args : any): Promise <void> {
    return new Promise((resolve,reject) =>  {
        try {
            const start = new Date().getTime();
            let now = start;
            while (now - start < duration) {
                now = new Date().getTime();
              }
            resolve(callback(args));
            }
        catch(error) {
            reject(error)
        }
    });
    
}
