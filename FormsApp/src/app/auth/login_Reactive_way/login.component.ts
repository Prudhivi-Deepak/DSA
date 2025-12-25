import { Component, DestroyRef, inject } from '@angular/core';
import { AbstractControl, FormControl, FormGroup, ReactiveFormsModule, ValidatorFn, Validators } from '@angular/forms';
import { debounceTime, of } from 'rxjs';

function questionMarkValidator(formControl: AbstractControl){
  if(formControl.value.includes('?')){
    return null;
  }

  return { questionMarkMissing: true };
}


function isExistingEmailValidator(formControl: AbstractControl){
  if(formControl.value !== 'test@example.com'){
    return of(null);
  }
  return of({ emailExists: true });
}


@Component({
  selector: 'app-login',
  imports: [ReactiveFormsModule],
  standalone: true,
  templateUrl: './login.component.html',
  styleUrl: './login.component.css',
})
export class LoginComponent {

  private destroyRef = inject(DestroyRef);

  form = new FormGroup({
    email : new FormControl('', { 
      validators: [Validators.required, Validators.email],
      asyncValidators: [isExistingEmailValidator]
    }),
    password : new FormControl('', { validators: [Validators.required, Validators.minLength(6), questionMarkValidator]}), 
  })

  ngOnInit(){

    const savedForm = window.localStorage.getItem('saved-email');
    if(savedForm){
      const parsedForm = JSON.parse(savedForm);

      // this.form.controls['email'].setValue(parsedForm.email);

      this.form.patchValue({ email: parsedForm.email } );      
    }

    const formSubscription = this.form.valueChanges.pipe(debounceTime(500)).subscribe({
      next: (value)=> {
        console.log('Form Value Changed:', value);
        window.localStorage.setItem('saved-email', JSON.stringify({ email: value.email }) );
      }
    })

    this.destroyRef.onDestroy(() => {
      formSubscription.unsubscribe();
    });

  }

  get emailIsValid(){
    return this.form.controls.email.touched && this.form.controls.email.dirty && this.form.controls.email.invalid
  }

  get passwordIsValid(){
    return this.form.controls.password.touched && this.form.controls.password.dirty && this.form.controls.password.invalid
  }

  onSubmit(){
    console.log('Form Submitted!', this.form);
  }
}