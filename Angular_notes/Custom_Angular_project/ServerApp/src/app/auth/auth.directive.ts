import { Directive, effect, ElementRef, inject, input, Renderer2, TemplateRef, ViewContainerRef } from '@angular/core';
import { type permission } from './auth.model';
import { AuthService } from './auth.service';

@Directive({
  selector: '[appAuth]',
  // standalone: true
})
export class AuthDirective {
  userType = input.required<permission>({alias: 'appAuth'});
  private authservice = inject(AuthService);

  private templateRef = inject(TemplateRef);
  private viewcontainerRef = inject(ViewContainerRef);

  constructor() {
    effect( ()=>{
      if(this.authservice.activePermission() === this.userType()){
        console.log("current user has authentication as:", this.userType());
        console.log("SHOW ELEMENT - ADMIN");
        this.viewcontainerRef.createEmbeddedView(this.templateRef);
      }else{
          console.log("current user does not have authentication as:", this.userType());
          console.log("DO NOT SHOW ELEMENT - NOT ADMIN");
          this.viewcontainerRef.clear();
      }
    });
  } 
}




