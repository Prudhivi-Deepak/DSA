import { afterNextRender, Component, DestroyRef, inject, viewChild } from '@angular/core';
import { FormsModule, NgForm } from '@angular/forms';
import { debounceTime } from 'rxjs';

@Component({
  selector: 'app-login',
  imports: [FormsModule],
  standalone: true,
  templateUrl: './login.component.html',
  styleUrl: './login.component.css',
})
export class LoginComponent {

  private form = viewChild.required<NgForm>('form');
  private destroyRef = inject(DestroyRef);

  constructor() {
    afterNextRender(() => {

      const savedForm = window.localStorage.getItem('saved-email');
      if (savedForm) {
        const parsedForm = JSON.parse(savedForm);
        // this.form().setValue({
        //   email: parsedForm.email,
        //   password: ''
        // });

        this.form().controls['email'].setValue(parsedForm.email);
      }

      const subscription = this.form().valueChanges?.pipe(
        debounceTime(500)
      ).subscribe({
        next: (value) => {
          console.log('Form Value Changed:', value);
          window.localStorage.setItem('saved-email', JSON.stringify({ email: value.email }));
        }
      })

      this.destroyRef.onDestroy(() => {
        subscription?.unsubscribe();
      });
    });
  }

  onNgSubmit(form: NgForm) {
    console.log('Form Submitted!', form);
    const email = form.form.value.email;
    const password = form.form.value.password;
    console.log('Email:', email);
    console.log('Password:', password);

    form.form.reset();
  }
}
