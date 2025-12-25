# ChangeDetection

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 15.2.10.

## Development server

Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The application will automatically reload if you change any of the source files.

## Code scaffolding

Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

## Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory.

## Running unit tests

Run `ng test` to execute the unit tests via [Karma](https://karma-runner.github.io).

## Running end-to-end tests

Run `ng e2e` to execute the end-to-end tests via a platform of your choice. To use this command, you need to first add a package that implements end-to-end testing capabilities.

## Further help

To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI Overview and Command Reference](https://angular.io/cli) page.

## Zone.js

>`Patched most standard API's (setTimeout, promises, DOM event listeners, XML HTTP requests in Browser, EventEmitter in Node.js, etc)`<br>
-> to notify Angular when to run change detection.

## To clarify
>`Change detection will run only --> if there was some event listener set up for that button click event`<br>
`Else If there is no event listener --> Angular will not be notified and change detection will not run.`

### (Double checks) 2 set of checks (CD) --> happens only in development mode 
 - My doubt what if use any **Math.random()** we get random number everytime right?<br>
 -> `Angular will check the value twice and if both values are not same then it will throw error in console.`
  
> **Error** : ***ExpressionChangedAfterItHasBeenCheckedError***: Expression has changed after it was checked. Previous value: '0'. Current value: '1'

`Avoid  using get functions in template bindings and try to use simple calculations inside the get functions if you are using them.`

> - setTimeout inside ngOnInit with a count value set to 0 --> runs and change detection happens<br>
> - setimeout inside ngOnInit with a console log which doesn't effect any template --> runs and change detection happens because all the listeners are patched by zone.js (under the hood, it listens to all event listeners and notifies angular to run change detection)

## NgZone - from @angular/core
[To optout of change detection we have to inject NgZone]()
`constructor(private ngZone: NgZone){}` or `private zone = inject(NgZone);`

zone has a function runOutsideAngular(()=> {}) --> any code inside this function will not trigger change detection, zone.js will not watch this code block.
Example:
<code>
<br>this.zone.runOutsideAngular(() => {<br>
&nbsp;&nbsp;&nbsp;&nbsp; setTimeout(() => {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;this.count++;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;console.log('Count value:', this.count);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}, 1000);<br>
&nbsp;&nbsp;&nbsp;&nbsp;});<br>
</code>

## onPush Strategy (opt-in change detection that can be applied component wise)




