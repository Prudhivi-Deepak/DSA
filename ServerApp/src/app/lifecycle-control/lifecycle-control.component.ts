import { Component } from '@angular/core';

// import { LifecycleComponent } from "./lifecycle/lifecycle.component";

@Component({
    selector: 'app-lifecycle-control',
    // standalone: true,
    templateUrl: './lifecycle-control.component.html',
    // imports: [LifecycleComponent]
})
export class LifecycleControlComponent {
  lifecycleComponentIsVisible = false;
  lifecycleInputText = 'Some Random Number: ' + Math.random() * 100;

  onToggleLifecycleComponentVisibility() {
    this.lifecycleComponentIsVisible = !this.lifecycleComponentIsVisible;
  }

  onChangeLifecycleInputText() {
    this.lifecycleInputText = 'Some Random Number: ' + Math.random() * 100;
  }
}
