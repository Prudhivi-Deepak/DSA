// JavaScript Automatic Semicolon Insertion (ASI) Example
// -----------------------------------------------------------------------------------
// ASI is a feature in JavaScript that automatically inserts semicolons at the end of statements
// when they are omitted. However, relying on ASI can lead to unexpected behavior in certain cases.
console.log("without semicolon - single statement")
console.log("without semicolon - multiple statement"); // semicolon added here - avoid ASI(Automatic Semicolon Insertion) issues
[1, 2, 3].forEach(num => console.log(num))
console.log("This line may cause an error if ASI is not handled properly");
// ---------single line comment --------------------------------------------------------------------------
/* multi line    ---> we "use strict"       --> to make old code work like modern code / Modern JS Automatically uses strict mode
    comment      ---> (function(){          --> this function alone uses strict mode
                            "use strict";
                             your code here
                        })();
*/
console.log("===================================================================================================");
// To create variable use --> let / const / var
// var --> variables are defined from beginning of function, no matter where the definition is
console.log("------------------------------------------- var hoisting example ----------------------------------");
function varTest() {
    phrase = "var hoisting works! --> var not there in function --> it becomes a global variable";
    // no var is defined yet, so phrase becomes a global variable
    console.log("phrase : ",phrase); // "Hello World"
    var phrase; // variable declaration is hoisted (raised to the top of the function)
}
varTest();

try {
    console.log("phrase outside function :", phrase); // "var hoisting works!" - phrase is now a global variable
} catch (error) {
    console.error("Error occurred:", error.message);
}

function varTest2() {
    console.log("phrase2 before declaration: ", phrase2); // undefined - variable declaration is hoisted, but not the assignment
    var phrase2 = "var hoisting example 2"; // executes here
    console.log("phrase2 after declaration: ", phrase2); // "var hoisting example 2"
}
varTest2();

//var --> has no block scope
console.log("----- var no block scope example/ a way to emulate it IIFE (Immediately-Invoked Function Expression) ------");
// syntax : (function(){ })();
(function() {
    var x = 10;
    console.log("Inside IIFE, x =", x); // 10
})(); //we are calling the function immediately after defining it
console.log("====================================================================================================");
console.log("------------------------------------------- let -----------------------------------------------");

let message;
message = "Hello, World!";
console.log("let defined & assigned message in separate line: ", message); // Output: Hello, World!

let message2 = "Hello, Universe!";
console.log("let defined & assigned message2 in single line: ", message2); // Output: Hello, Universe!

let name = "Alice", age = 30, city = "New York";
console.log("let multiple variables in single line: ", name, age, city); // Output: Alice 30 New York

console.log("------------------------------------------- copy data -----------------------------------------");
// copying data from one variable to another
let original = "Original Value";
let copy = original;
console.log("copy of original using let: ", copy); // Output: Original Value
// we can define variable without let keyword --> only works in non strict mode
console.log("===================================================================================================");
console.log("------------------------------------------- const ----------------------------------------------");
// const variable must be initialized at the time of declaration
const PI = 3.14159;
console.log("const PI: ", PI); // Output: 3.14159

// const with objects and arrays
const person = { name: "John", age: 25 };
console.log("const object person before: ", person); // Output: { name: "John", age: 25 }
person.age = 26; // Allowed: modifying properties of the object
console.log("const object person after : ", person); // Output: { name: "John", age: 26 }

console.log("===================================================================================================");
// list of reserved words in JavaScript that cannot be used as variable names
const reservedWords = [
    "break", "case", "catch", "class", "const", "continue", "debugger", "default", "delete", "do", "else",
    "export", "extends", "finally", "for", "false", "function", "if", "import", "in", "instanceof", "new", "null",
    "return", "super", "switch", "this", "throw", "true", "try", "typeof", "var", "void", "while", "with", "yield"
];
const additionalReservedWords = [
    "enum", "await", "implements", "package", "protected", "static", "interface", "private", "public", "let"
];
reservedWords.push(...additionalReservedWords);
console.log("Reserved words in JavaScript: ", reservedWords);
console.log("===================================================================================================");



