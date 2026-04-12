let hello = "hello world";
let msg; msg = hello;
console.log("msg : ", msg); // "hello world"
console.log("hello : ", hello); // "hello world"

msg = "new value";
console.log("msg : ", msg); // "new value"
console.log("hello : ", hello); // "hello world" - original variable is unchanged

let number = 12;
let booleanValue = true;
let stringValue = "This is a string"; // single or double quotes or back ticks can be used for strings in JavaScript
let BigIntValue = 1234567890123456789012345678901234567890n; // BigInt literal with 'n' suffix
let SymbolValue = Symbol("unique identifier");
let NullValue = null; // seperate type in JavaScript, represents intentional absence of any object value
let UndefinedValue; // undefined by default

console.log("number : ", number);
console.log("booleanValue : ", booleanValue);
console.log("stringValue : ", stringValue);
console.log("BigIntValue : ", BigIntValue);
console.log("SymbolValue : ", SymbolValue);
console.log("NullValue : ", NullValue);
console.log("UndefinedValue : ", UndefinedValue);

console.log("====================================================================================================");

console.log(number,typeof(number)); // "number"
console.log(booleanValue,typeof(booleanValue)); // "boolean"
console.log(stringValue,typeof(stringValue)); // "string"
console.log(BigIntValue,typeof(BigIntValue)); // "bigint"
console.log(SymbolValue,typeof(SymbolValue)); // "symbol"
console.log(NullValue,typeof(NullValue)); // "object" - this is a known quirk in JavaScript, null is considered an object type
console.log(UndefinedValue,typeof(UndefinedValue)); // "undefined"
console.log(function(){},typeof(function(){})); // "function" - functions are a special type of object in JavaScript
console.log(Math,typeof(Math)); // "object" - Math is a built-in object in JavaScript

// alert("This is an alert box!"); // shows a pop-up alert box with the specified message
// prompt("Please enter your name:", 100); // shows a pop-up prompt box that asks the user for input and returns the input as a string
// confirm("Do you want to proceed?"); // shows a pop-up confirmation box that asks the user to confirm an action and returns true if the user clicks "OK" and false if the user clicks "Cancel"

// String(), NUmber(), Boolean() are global functions that can be used to convert values to their respective types
console.log("====================================================================================================");
console.log("String()");
console.log(String(123)); // "123" --> converts any value to string
console.log(String(true)); // "true"
console.log(String(null)); // "null"
console.log(String(undefined)); // "undefined"
console.log(String({})); // "[object Object]" - converts an object to a string representation
console.log(String([1, 2, 3])); // "1,2,3" - converts an array to a comma-separated string
console.log(String(function(){})); // "function(){}" - converts a function to its string representation
console.log(String(Symbol("sym"))); // "Symbol(sym)" - converts a symbol to its string representation
console.log(String(1234567890123456789012345678901234567890n)); // "1234567890123456789012345678901234567890" - converts a BigInt to a string
console.log(String(NaN)); // "NaN" - converts NaN to a string
console.log(String(Infinity)); // "Infinity" - converts Infinity to a string
console.log(String(-Infinity)); // "-Infinity" - converts -Infinity to a string

console.log("====================================================================================================");
console.log("Number()");
console.log(Number("\n\t")); // 0 - converts an empty string to a number (\n\t are whitespace characters)
console.log(Number("   1")); // 1 - converts a string with leading/trailing whitespace to a number
console.log(Number("1   ")); // 1 - converts a string with leading/trailing whitespace to a number
console.log(Number("123")); // 123 - converts a string to a number
console.log(Number("123.45")); // 123.45 - converts a string with decimal to a number
console.log(Number("abc")); // NaN - cannot convert non-numeric string to a number
console.log(Number(true)); // 1 - converts true to 1
console.log(Number(false)); // 0 - converts false to 0
console.log(Number(null)); // 0 - converts null to 0
console.log(Number(undefined)); // NaN - cannot convert undefined to a number
console.log(Number({})); // NaN - cannot convert an object to a number
console.log(Number([1, 2, 3])); // NaN - cannot convert an array to a number
console.log(Number(function(){})); // NaN - cannot convert a function to a number
// console.log(Number(Symbol("sym"))); // TypeError - cannot convert a symbol to a number
console.log(Number(1234567890123456789012345678901234567890n)); // 1.2345678901234568e+39 - converts a BigInt to a number, but may lose precision
console.log(Number(NaN)); // NaN - Number of NaN is still NaN
console.log(Number(Infinity)); // Infinity - Number of Infinity is still Infinity
console.log(Number(-Infinity)); // -Infinity - Number of -Infinity is still -Infinity
console.log("====================================================================================================");
console.log("Boolean()");
console.log(Boolean(" ")); // true - non-empty string is truthy
console.log(Boolean("")); // false - empty string is falsy
console.log(Boolean(0)); // false - 0 is falsy
console.log(Boolean(-0)); // false - -0 is falsy
console.log(Boolean(0n)); // false - BigInt 0 is falsy
console.log(Boolean(false)); // false - false is falsy
console.log(Boolean(null)); // false - null is falsy
console.log(Boolean(undefined)); // false - undefined is falsy
console.log(Boolean(NaN)); // false - NaN is falsy
console.log(Boolean(Infinity)); // true - Infinity is truthy
console.log(Boolean(-Infinity)); // true - -Infinity is truthy
console.log(Boolean(true)); // true - true is truthy
console.log(Boolean("hello")); // true - non-empty string is truthy
console.log(Boolean(123)); // true - non-zero number is truthy
console.log(Boolean(123n)); // true - non-zero BigInt is truthy
console.log(Boolean({})); // true - non-null object is truthy
console.log(Boolean([])); // true - non-null object (array) is truthy
console.log(Boolean(function(){})); // true - non-null object (function) is truthy
console.log(Boolean(Symbol("sym"))); // true - non-null object (symbol) is truthy


// +  converts operands to strings if either operand is a string, otherwise it performs numeric addition from left to right
console.log("====================================================================================================");
console.log("Type coercion with + operator:");
console.log("1 + 2 =", 1 + 2); // 3 - both operands are numbers, so it performs numeric addition
console.log("'1' + 2 =", '1' + 2); // "12" - one operand is a string, so it performs string concatenation
console.log("1 + '2' =", 1 + '2'); // "12" - one operand is a string, so it performs string concatenation
console.log("'1' + '2' =", '1' + '2'); // "12" - both operands are strings, so it performs string concatenation
console.log("1+2+'4' =", 1+2+'4'); // "34" - 1+2 is evaluated first to 3, then '3' + '4' is evaluated to "34"
console.log("'4'+1+2 =", '4'+1+2); // "412" - '4' + 1 is evaluated first to "41", then "41" + 2 is evaluated to "412"

// but all other operators convert operands to numbers
console.log("====================================================================================================");
console.log("Type coercion with other operators:");
console.log("1 - '2' =", 1 - '2'); // -1 - both operands are converted to numbers, so it performs numeric subtraction
console.log("1 * '2' =", 1 * '2'); // 2 - both operands are converted to numbers, so it performs numeric multiplication
console.log("1 / '2' =", 1 / '2'); // 0.5 - both operands are converted to numbers, so it performs numeric division
console.log("1 % '2' =", 1 % '2'); // 1 - both operands are converted to numbers, so it performs numeric modulus
console.log("5+'9-'4' =", 5+'9'-'4'); // 10 - '9' is converted to 9, '4' is converted to 4, so it performs numeric addition and subtraction
console.log("'5'+'9'-'4' =", '5'+'9'-'4'); // 50 - '5' + '9' is evaluated first to "59", then "59" - '4' is evaluated to 55 (string "59" is converted to number 59, '4' is converted to 4)
console.log("5+'9'-4 =", 5+'9'-4); // 10 - '9' is converted to 9, so it performs numeric addition and subtraction

console.log("====================================================================================================");
console.log("Precedence of operators:");
console.log("Unary > Multiplicative > Additive > Relational > Equality > Logical AND > Logical OR > Assignment");


