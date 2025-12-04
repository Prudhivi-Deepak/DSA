import { CommonModule } from "@angular/common";
import { NgModule } from "@angular/core";
import { FormsModule } from "@angular/forms";
import { AuthComponent } from "./auth.component";
import { LogDirective } from "../log.directive";
import { AuthDirective } from "./auth.directive";

@NgModule({
    declarations: [AuthComponent, AuthDirective],
    imports: [CommonModule, FormsModule],
    exports: [AuthComponent, AuthDirective],
})
export class AuthModule { }