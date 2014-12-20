package phoenix3d.px2.library;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.media.AudioManager;
import android.media.SoundPool;
import android.media.MediaPlayer;
import android.util.Log;

public class PX2SoundSystem
{
	private Context mContext;
	private SoundPool mSoundPool;
	private HashMap<Integer, Integer> mSoundIDStreamIDMap;
	private HashMap<String, Integer> mPathSoundIDMap;
	
	private static final int MAX_SIMULTANEOUS_STREAMS_DEFAULT = 20; // 同时允许播放最大流数量	
	private static final float SOUND_RATE = 1.0f;
	private static final int SOUND_PRIORITY = 1;
	private static final int SOUND_QUALITY = 0;	
	private final int INVALID_SOUND_ID = -1;
	private final int INVALID_STREAM_ID = -1;
	
	private MediaPlayer mMediaPlayers[];
	private String mMedialPaths[];
	
	public PX2SoundSystem(Context context){
		this.mContext = context;	
		Initlize();
	}
	
	public boolean Initlize ()
	{
		mSoundPool = new SoundPool(MAX_SIMULTANEOUS_STREAMS_DEFAULT, AudioManager.STREAM_MUSIC, SOUND_QUALITY);
		mSoundIDStreamIDMap = new HashMap<Integer,Integer>();		
		mPathSoundIDMap = new HashMap<String,Integer>();
		
		mMediaPlayers = new MediaPlayer[4];		
		mMedialPaths = new String[4];	

		return true;
	}	
	
	public void Clear ()
	{
		mSoundPool.release();	
		mPathSoundIDMap.clear();	
		mSoundIDStreamIDMap.clear();
		
		for (int i=0; i<4; i++)
		{
			if (null != mMediaPlayers[i])
				mMediaPlayers[i].release();
		}
	}
	
	// Sound
	public Integer PlaySound2D (String path, float volume, boolean isLoop)
	{
		Integer soundID = mPathSoundIDMap.get(path);
		
		if (null == soundID)
		{
			soundID = LoadSound(path);
		}
		
		if (INVALID_SOUND_ID == soundID)
			return soundID;
		
		int streamID = mSoundPool.play(soundID, 100.0f, 100.0f, SOUND_PRIORITY,
				isLoop ? -1 : 0, SOUND_RATE);
		
		mSoundIDStreamIDMap.put(soundID, streamID);
		
		return soundID;
	}
	
	public void SetSoundVolume(int soundID, float volume)
	{	
		if (volume < 0)
		{
			volume = 0;
		}	
		if (volume > 1)
		{
			volume = 1;
		}
		
	    Integer streamID = mSoundIDStreamIDMap.get(soundID);
	    
	    if (streamID != null && streamID.intValue() != INVALID_STREAM_ID)
	    {
	    	mSoundPool.setVolume(streamID, volume, volume);
	    }
	}	

	public void StopSound (int soundID)
	{
   /*     Integer streamID = mSoundIDStreamIDMap.get(soundID);
        
        if (streamID != null && streamID.intValue() != INVALID_STREAM_ID)
        {
        	mSoundPool.stop(streamID.intValue());
        	mPathSoundIDMap.remove(soundID);
        } */
	}
	
	public void PauseSound (int soundID)
	{
		/*
        Integer streamID = mSoundIDStreamIDMap.get(soundID);
        
        if (streamID != null && streamID.intValue() != INVALID_STREAM_ID)
        {
        	this.mSoundPool.pause(streamID.intValue());
        	this.mPathSoundIDMap.remove(soundID);
        }
        */
	}
	
	public void ResumeSound (int soundID)
	{
		/*
        Integer streamID = mSoundIDStreamIDMap.get(soundID);
        
        if (streamID != null && streamID.intValue() != INVALID_STREAM_ID)
        {
        	this.mSoundPool.resume(streamID.intValue());
        	this.mPathSoundIDMap.remove(soundID);
        }
        */
	}	
	
	public int LoadSound (String path)
	{
		int soundId = INVALID_SOUND_ID;
		
		if (mPathSoundIDMap.get(path) != null)
		{
			soundId = mPathSoundIDMap.get(path).intValue();
		} 
		else 
		{
			soundId = CreateSoundIdFromAsset(path);
			
			if (soundId != INVALID_SOUND_ID)
			{
				mSoundIDStreamIDMap.put(soundId, INVALID_STREAM_ID);
				
				mPathSoundIDMap.put(path, soundId);
			}
		}
			
		return soundId;
	}
	
	public void UnloadSound (String path)
	{
		Integer soundID = mPathSoundIDMap.remove(path);
		
		if (null != soundID)
		{
			mSoundPool.unload(soundID.intValue());
			mSoundIDStreamIDMap.remove(soundID);
		}
	}
	
	public int CreateSoundIdFromAsset(String path)
	{
		int soundId = INVALID_SOUND_ID;
		
		try
		{
			if (path.startsWith("DataUpdateAndroid/"))
			{
				soundId = mSoundPool.load(path, 0);
			}
			else
			{
				soundId = mSoundPool.load(mContext.getAssets().openFd(path), 0);
			}			
		}
		catch (Exception e)
		{
			soundId = INVALID_SOUND_ID;
		}
		
		return soundId;
	}
		
	// Music
	public void PlayMusic (int channel, String path, float volume, boolean isLoop)
	{		
		MediaPlayer player = mMediaPlayers[channel];
		String medialPath = mMedialPaths[channel];		
		
		if (medialPath == path)
		{
		}
		else
		{
			if (null != player)
			{
				player.release();
			}
			
			player = CreateMusicFromAsset(path);
			mMediaPlayers[channel] = player;
			mMedialPaths[channel] = path;
		}		
	
		if (null != player)
		{
			try
			{
				player.stop();
				player.setVolume(volume, volume);
				player.setLooping(isLoop);
				player.prepare();
				player.seekTo(0);
				player.start();
			}
			catch (Exception e)
			{
			}	
		}
	}
	
	void SetMusicVolume (int channel, float volume)
	{
		MediaPlayer player = mMediaPlayers[channel];
		
		if (null != player)
		{
			player.setVolume(volume, volume);
		}
	}
	
	void StopMusic (int channel)
	{
		MediaPlayer player = mMediaPlayers[channel];
		
		if (null != player)
		{
			player.stop();
		}
	}
	
	private MediaPlayer CreateMusicFromAsset (String path)
	{
		MediaPlayer mediaPlayer = new MediaPlayer();
		
		try
		{
			if (path.startsWith("DataUpdateAndroid/"))
			{
				mediaPlayer.setDataSource(path);
			}
			else 
			{
				AssetFileDescriptor assetFileDescritor = mContext.getAssets().openFd(path);
		        mediaPlayer.setDataSource(assetFileDescritor.getFileDescriptor(), 
		        		assetFileDescritor.getStartOffset(), assetFileDescritor.getLength());				
			}
			
	        mediaPlayer.prepare();
		}
		catch (Exception e)
		{			
			mediaPlayer = null;
        }
		
        return mediaPlayer;
	}
	
};