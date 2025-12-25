import { ResolveFn } from '@angular/router';
import { canLeavePage, NewTaskComponent } from '../tasks/new-task/new-task.component';
import { TasksService } from '../tasks/tasks.service';
import { resolverFunctionForTitle } from './user-tasks/user-tasks.component';
import { Task } from '../tasks/task/task.model';
import { inject } from '@angular/core';


const resolveUserTasks: ResolveFn<Task[]> = (
    activatedRouteSnapshot,
    routerState

) => {
    const order = activatedRouteSnapshot.queryParams['order'];
    const tasksService = inject(TasksService);
    const tasks = tasksService
        .allTasks()
        .filter(
            (task) => task.userId === activatedRouteSnapshot.paramMap.get('userId')
        );

    if (order && order === 'asc') {
        tasks.sort((a, b) => (a.id > b.id ? 1 : -1));
    } else {
        tasks.sort((a, b) => (a.id > b.id ? -1 : 1));
    }

    return tasks.length ? tasks : [];
};


export const userRoutes = [
    {
        path: '',
        providers: [TasksService],
        children: [
            {
                path: 'tasks',
                loadComponent: () => import('../tasks/tasks.component').then(m => m.TasksComponent),
                // component: TasksComponent,
                // runGuardsAndResolvers: 'paramsOrQueryParamsChange',
                runGuardsAndResolvers: 'always' as const,
                resolve: {
                    userTasks: resolveUserTasks,
                },
                title: resolverFunctionForTitle
            },
            {
                path: 'tasks/new', component: NewTaskComponent,
                canDeactivate: [canLeavePage]
            }
        ]
    }
];