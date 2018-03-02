/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:30:10 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:30:51 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sg.h>
#include <fcntl.h>
#include <unistd.h>

static GLuint	vertex_shader(char const *file)
{
	char		*vertex_shader;
	char		*tmp;
	GLuint		vs;
	int			fd;
	char		buff[4096];

	if (!(vertex_shader = ft_strnew(0)))
		return (0);
	fd = open(file, O_RDONLY);
	ft_bzero(buff, 4096);
	while (read(fd, buff, 4096) > 0)
	{
		tmp = ft_strjoin(vertex_shader, buff);
		free(vertex_shader);
		vertex_shader = tmp;
		ft_bzero(buff, 4096);
	}
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, (const char *const *)&vertex_shader, NULL);
	glCompileShader(vs);
	free(vertex_shader);
	return (vs);
}

static GLuint	fragment_shader(char const *file)
{
	char		*fragment_shader;
	char		*tmp;
	GLuint		fs;
	int			fd;
	char		buff[4096];

	if (!(fragment_shader = ft_strnew(0)))
		return (0);
	fd = open(file, O_RDONLY);
	ft_bzero(buff, 4096);
	while (read(fd, buff, 4096) > 0)
	{
		tmp = ft_strjoin(fragment_shader, buff);
		free(fragment_shader);
		fragment_shader = tmp;
		ft_bzero(buff, 4096);
	}
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, (const char *const *)&fragment_shader, NULL);
	glCompileShader(fs);
	free(fragment_shader);
	return (fs);
}

GLuint			get_shader_prog(char const *fs_file, char const *vs_file)
{
	GLuint		shader_prog;
	GLuint		fragment;
	GLuint		vertex;

	shader_prog = glCreateProgram();
	fragment = fragment_shader(fs_file);
	vertex = vertex_shader(vs_file);
	if (vertex == 0 || fragment == 0)
		return (0);
	glAttachShader(shader_prog, fragment);
	glAttachShader(shader_prog, vertex);
	glLinkProgram(shader_prog);
	return (shader_prog);
}
