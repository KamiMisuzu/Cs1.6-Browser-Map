// // let fn = function() {
// //     console.log("Hello First-class Funtion")
// // }
// function forEach(array,fn){
//     for (let i = 0; i < array.length;i++){
//         fn(array[i])
//     }
// }

// let arr = [1,2,3,4,5,6];
// forEach(arr,function (item) {
//     console.log(item);
// })
// function makeFn(){
//     let msg="Hello function"
//     return function(){
//         console.log(msg)
//     }
// }
// makeFn()()

// function once(fn){
//     let done = false;
//     return function(){
//         if(!done){
//             done =true;
//             return fn.apply(null,arguments);
//         }
//     }
// }
// let pay = once(function (money) {
//     console.log(`支付: ${money} RMB`)
// })

// pay(5)
// pay(5)
// pay(5)
// pay(5)

// function MakePower (power){
//     return function (number) {
//         return Math.pow(number,power)
//     }
// }
// let power2 = makePower(2)
// let power3 = makePower(3)
 
// const _ = require('lodash')

// function memoize(fn){
//     let cache = {} 
//     return function(){
//         let key = JSON.stringify(arguments)
//         cache[key] = cache[key]  || fn.apply(f,arguments);
//         return cache[key]
//     }
// }

// function checkAge(min){
//     return function (age){
//         return age>= min;
//     }
// }
// let checkAge = min => (age=> age>=min); //es6 

// let chechAge18 =checkAge(18); //设置基准值18
// let chechAge20 = chechAge(20); //设置基准值20
// //这个函数就是柯里化的过程,将多参数函数变为单个参数的不同函数