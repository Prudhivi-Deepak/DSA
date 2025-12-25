import { Component, inject, DestroyRef, signal } from '@angular/core';
import {toObservable, toSignal} from '@angular/core/rxjs-interop'
import {interval, map, Observable} from 'rxjs';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'RXJSapp';

  clickCount = signal(0);
  clickCount$ = toObservable(this.clickCount); // Converting signal to observable
  interval$ = interval(1000);
  intervalSignal = toSignal(this.interval$, {initialValue:0});

  customInterval$ = new Observable((subscriber)=>{
    let timer = 0;
    const interval = setInterval(()=>{
      if(timer>5){
        clearInterval(interval);
        subscriber.complete();
        return;
      }
      subscriber.next({message : 'Hello from custom observable'+ timer});
      timer++;
    }, 1000);
  });

  private destoryRef = inject(DestroyRef);

  // constructor(){
  //   effect(()=> {
  //     console.log('click count changed to ' + this.clickCount());
  //   })
  // }


  ngOnInit(){

    // interval(1000).subscribe((val)=>{
    //   console.log(val);
    // });

    // const intervalSubscription = interval(1000).pipe(
    //   map((val)=>val*3)
    // ).subscribe({
    //   next: (val)=>console.log(val),
    //   complete: ()=>console.log('completed'),
    //   error: (err)=>console.log('error occured' + err)
    // });

    this.customInterval$.subscribe({
      next:(val)=>console.log(val),
      complete: ()=>console.log('custom observable completed'),
    });

    // creating subscription for observable clickCount
    const intervalSubscription = this.clickCount$.subscribe({
      next: (val)=>console.log("val : ",val),
    });


    this.destoryRef.onDestroy(()=>{
      intervalSubscription.unsubscribe();
    });
  }

    onClick(){
      this.clickCount.update((count)=>count+1);
      console.log('button clicked' + this.clickCount());
    }
}

