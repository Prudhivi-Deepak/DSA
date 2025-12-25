import { NgFor, NgIf } from '@angular/common';
import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  standalone: false,
  templateUrl: './app.component.html',
  // imports: [NgFor, NgIf],
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  
}
// ------------------------------------------------------



// ------------------------------------------------------

// import { Component } from '@angular/core';

// import { LifecycleComponent } from "./lifecycle/lifecycle.component";

// @Component({
//     selector: 'app-root',
//     standalone: true,
//     templateUrl: './app.component.html',
//     imports: [LifecycleComponent]
// })
// export class AppComponent {
//   lifecycleComponentIsVisible = false;
//   lifecycleInputText = 'Some Random Number: ' + Math.random() * 100;

//   onToggleLifecycleComponentVisibility() {
//     this.lifecycleComponentIsVisible = !this.lifecycleComponentIsVisible;
//   }

//   onChangeLifecycleInputText() {
//     this.lifecycleInputText = 'Some Random Number: ' + Math.random() * 100;
//   }
// }

// ------------------------------------------------------