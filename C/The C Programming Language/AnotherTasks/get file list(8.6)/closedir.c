void closedir(DIR* dp)
{
	if(dp)
	{
		close(dp->fd);
		free(dp);
	}
}
