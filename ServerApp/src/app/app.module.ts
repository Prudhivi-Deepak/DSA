import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { FormsModule } from '@angular/forms';
import { ServerStatusComponent } from './server-status/server-status.component';
import { ServerTrafficComponent } from './server-traffic/server-traffic.component';
import { SupportTicketsComponent } from './support-tickets/support-tickets.component';
import { DashboardItemComponent } from './dashboard-item/dashboard-item.component';
import { NewTicketComponent } from './tickets/new-ticket/new-ticket.component';
import { ButtonModule } from './shared/button/button.module';
import { ControlComponent } from './shared/control/control.component';
import { HeaderComponent } from './header/header.component';
import { LifecycleComponent } from './lifecycle/lifecycle.component';
import { LifecycleControlComponent } from './lifecycle-control/lifecycle-control.component';
import { TicketComponent } from './tickets/ticket/ticket.component';
import { SafeLinkDirective } from './safe-link.directive';
import { AuthDirective } from './auth/auth.directive';
import { AuthComponent } from './auth/auth.component';
import { LogDirective } from './log.directive';
import { AuthModule } from './auth/auth.module';

@NgModule({
  declarations: [
    AppComponent,
    ServerStatusComponent,
    ServerTrafficComponent,
    SupportTicketsComponent,
    DashboardItemComponent,
    NewTicketComponent,
    ControlComponent,
    HeaderComponent,
    LifecycleComponent,
    LifecycleControlComponent,
    TicketComponent,
    // AuthComponent,

    SafeLinkDirective,
    // AuthDirective,
    // LogDirective
  ],
  imports: [
    BrowserModule, FormsModule, ButtonModule, AuthModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
