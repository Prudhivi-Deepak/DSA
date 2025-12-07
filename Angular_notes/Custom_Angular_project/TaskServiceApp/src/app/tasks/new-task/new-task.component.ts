import { Component, ElementRef, Inject, inject, viewChild } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { TasksService } from '../tasks.service';
import { TokenServiceToken } from 'src/app/app.module';
// import { TokenServiceToken } from 'src/main';

@Component({
  selector: 'app-new-task',
  // standalone: true,
  // imports: [FormsModule],
  templateUrl: './new-task.component.html',
  styleUrl: './new-task.component.css',
})
export class NewTaskComponent {
  private formEl = viewChild<ElementRef<HTMLFormElement>>('form');

  // private taskService = inject(TasksService);
  // private taskService = inject(TokenServiceToken);
  constructor(@Inject(TokenServiceToken) private taskService: TasksService){}

  onAddTask(title: string, description: string) {
    this.taskService.addTasks({ title, description });
    this.formEl()?.nativeElement.reset();
  }
}
